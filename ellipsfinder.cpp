#include "ellipsfinder.h"

Ellipsfinder::Ellipsfinder()
{
    Pixels.clear();
    ellipsCenters.clear();
    ellipshMA.clear();
    ellipshMI.clear();
    ellipsorientations.clear();
}

Ellipsfinder::Ellipsfinder(cv::Mat inputimage)
{
    newImage(inputimage);
    //std::cout<<Pixels.size()<<std::endl;
    //Algoritm(minMA,minhMI,th10);
}


void Ellipsfinder::Algoritm(unsigned minMA, unsigned minhMI, unsigned th10, unsigned MIuniqueness)
{
    //clearing old ellipses
    ellipsCenters.clear();
    ellipshMA.clear();
    ellipshMI.clear();
    ellipsorientations.clear();
    //declaring variables
    std::set<unsigned> Pointsonellips;//all indices of point on ellipses will be put in this set
                                      //because a point can only be on one ellipse so this will be used to check this
    std::vector<cv::Point> leftoverPixels=Pixels;

    //running algoritm
    for(unsigned PPI=0;PPI<Pixels.size();++PPI)//PPI primary pixel index
    {
        const cv::Point &PrimaryPixel=Pixels.at(PPI);


        if(!Pointsonellips.count(PPI))//Check if the point is already on an ellips
        {
            for(unsigned CPI=PPI+1;CPI<Pixels.size();++CPI)//CPI current pixel index
            {

                const cv::Point &CurrentPixel=Pixels.at(CPI);

                if(!Pointsonellips.count(CPI) && getDist(PrimaryPixel,CurrentPixel)>=minMA)//check if CP is not already on ellips && check if dist>thershold
                {
                    cv::Point Center=getCenter(PrimaryPixel,CurrentPixel);
                    double MA=getHalflengthMaA(PrimaryPixel,CurrentPixel);
                    std::vector<unsigned> accumulator(static_cast<unsigned>(round(MA))-1,0);//vector with the size of the diagonal/2 in pixels each vector position is the size of minor axis-1
                                                                                            //this is the maximum and ellips could realisticly be

                    unsigned accumulatorsize=accumulator.size();
                    if(accumulatorsize==0)continue;
                    std::vector<std::vector<unsigned>> accumulatorPoints;//vector of vectors with all the indices of the point that belong to the corresponding minor axis and ellips
                    accumulatorPoints.resize(accumulator.size());

                    for(unsigned OPI=0;OPI<leftoverPixels.size();++OPI)//OPI other pixel index
                    {
                        const cv::Point &OtherPixel=leftoverPixels.at(OPI);
                        if(OtherPixel!=PrimaryPixel&&OtherPixel!=CurrentPixel&&getDist(Center,OtherPixel)>=minhMI)
                        {   
                            double dist=getDist(Center,OtherPixel);
                            if(dist>minhMI&&dist<MA)
                            {
                                unsigned MiA=static_cast<unsigned>(round(getHalflengthMiA(MA,Center,CurrentPixel,OtherPixel)));
                                if(MiA>minhMI&&MiA<accumulatorsize-1)
                                {
                                    ++accumulator.at(MiA-1);//increasing accumulator
                                    (accumulatorPoints.at(MiA-1)).push_back(OPI);//saving Pixel index so it can be deleted later
                                }
                            }
                        }
                    }

                    //finding maximum element in accumulator
                    std::vector<unsigned>::const_iterator itermax=max_element(accumulator.begin(),accumulator.end());
                    //std::cout<<"max is:"<<*itermax<<std::endl;
                    if(*itermax>th10)
                    {
                        //std::cout<<"Ellips found!!!"<<std::endl;
                        unsigned b=itermax-accumulator.begin()+1;
                        //adding points of new ellips to pointsonellips set
                        Pointsonellips.insert((accumulatorPoints.at(b-1)).begin(),(accumulatorPoints.at(b-1)).end());
                        Pointsonellips.insert(PPI);
                        Pointsonellips.insert(CPI);
                        //adding point from the accumulator that are near the max
                        for(unsigned i=0; i<MIuniqueness;++i)
                        {
                            if(b-1-i>0)Pointsonellips.insert((accumulatorPoints.at(b-1-i)).begin(),(accumulatorPoints.at(b-1-i)).end());
                            if(b-1+i<accumulatorsize)Pointsonellips.insert((accumulatorPoints.at(b-1+i)).begin(),(accumulatorPoints.at(b-1+i)).end());
                        }
                        //Changing leftoverpoints vector
                        //the loop will add all elements of leftoverPixels adds all pixels to newleftoverpixels that are not on the ellips
                        //We could also use the erase function but because erase is very inefficient and we have to delete different elements on different
                        //positions the loop will be faster

                        std::vector<cv::Point> newleftoverPixels;
                        for(unsigned index=0;index<leftoverPixels.size();++index)
                        {
                            if(!Pointsonellips.count(index))newleftoverPixels.push_back(leftoverPixels.at(index));
                        }
                        leftoverPixels=newleftoverPixels;


                        //adding ellips to output variables
                        ellipsCenters.push_back(getCenter(PrimaryPixel,CurrentPixel));
                        ellipshMA.push_back(static_cast<unsigned>(round(getHalflengthMaA(PrimaryPixel,CurrentPixel))));
                        ellipshMI.push_back(b);
                        ellipsorientations.push_back(getOrientation(PrimaryPixel,CurrentPixel));
                        //std::cout<<leftoverPixels.size()<<std::endl;
                    }
                }

            }
        }

    }

}

void Ellipsfinder::getEllipses(std::vector<cv::Point> &Centers, std::vector<unsigned> &hMA, std::vector<unsigned> &hMI, std::vector<double> &orientation, unsigned minMA, unsigned minhMI, unsigned th10, unsigned MIuniqueness)
{
    Algoritm(minMA,minhMI,th10,MIuniqueness);
    Centers=ellipsCenters;
    hMA=ellipshMA;
    hMI=ellipshMI;
    orientation=ellipsorientations;
}

void Ellipsfinder::newImage(cv::Mat inputimage)
{
    Pixels.clear();
    ellipsCenters.clear();
    ellipshMA.clear();
    ellipshMI.clear();
    ellipsorientations.clear();

    IMrows=inputimage.rows;
    IMcols=inputimage.cols;
    for(int r=0;r<inputimage.rows;++r)
    {
        for(int c=0;c<inputimage.cols;++c)
        {
            if(inputimage.at<uchar>(r,c)==255)
            {
                cv::Point coord(c,r);
                Pixels.push_back(coord);
            }

        }
    }
}

cv::Point Ellipsfinder::getCenter(const cv::Point &Pone, const cv::Point &Ptwo) const
{
    double x0=static_cast<double>((Pone.x+Ptwo.x))/2;
    double y0=static_cast<double>((Pone.y+Ptwo.y))/2;
    cv::Point center(x0,y0);
    return center;
}

double Ellipsfinder::getHalflengthMaA(const cv::Point &Pone, const cv::Point &Ptwo) const
{
    return sqrt(pow(Ptwo.x-Pone.x,2)+pow(Ptwo.y-Pone.y,2))/2;

}

double Ellipsfinder::getOrientation(const cv::Point &Pone, const cv::Point &Ptwo) const
{
    if(Pone==Ptwo)
    {
        std::cout<<"To point given to getOrientation are the same!"<<std::endl;
        exit (EXIT_FAILURE);
    }

    if(Ptwo.x==Pone.x) return CV_PI/2;
    return atan2((Ptwo.y-Pone.y),(Ptwo.x-Pone.x));
}

double Ellipsfinder::getCosTau(const double a,const cv::Point& Pzero,const cv::Point &Ptwo, const cv::Point &Prandom) const
{
    double d=getDist(Pzero,Prandom);
    double f=getDist(Ptwo,Prandom);
    return (pow(a,2)+pow(d,2)-pow(f,2))/(2*a*d);
}

double Ellipsfinder::getDist(const cv::Point &Pone, const cv::Point &Ptwo) const
{
    return sqrt(pow(Ptwo.x-Pone.x,2)+pow(Ptwo.y-Pone.y,2));
}

double Ellipsfinder::getHalflengthMiA(const double a, const cv::Point &Pzero, const cv::Point &Ptwo, const cv::Point &Prandom) const
{
    double d=getDist(Pzero,Prandom);
    double costau=getCosTau(a, Pzero, Ptwo, Prandom);
    double sintau=sin(acos(costau));
    return sqrt((pow(a,2)*pow(d,2)*pow(sintau,2))/(pow(a,2)-pow(d,2)*pow(costau,2)));
}

