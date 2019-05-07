#include "ellipsfinder.h"


Ellipsfinder::Ellipsfinder(cv::Mat inputimage, unsigned minhMA, unsigned minhMI, unsigned th10):IMrows(inputimage.rows),IMcols(inputimage.cols)
{
    Pixels.clear();
    thresholdstep4=minhMA;
    thresholdstep6=minhMI;
    thresholdstep10=th10;
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
    //std::cout<<Pixels.size()<<std::endl;
    Algoritm();
}


void Ellipsfinder::Algoritm()
{
    std::set<unsigned> Pointsonellips;//all indices of point on ellipses will be put in this set
                                      //because a point can only be on one ellipse so this will be used to check this

    for(unsigned PPI=0;PPI<Pixels.size();++PPI)//PPI primary pixel index
    {
        const cv::Point &PrimaryPixel=Pixels.at(PPI);
        //std::cout<<"###########################"<<std::endl;
        //std::cout<<"PPI:"<<PrimaryPixel<<std::endl;

        if(!Pointsonellips.count(PPI))//Check if the point is already on an ellips
        {
            for(unsigned CPI=PPI+1;CPI<Pixels.size();++CPI)//CPI current pixel index
            {
                std::vector<unsigned> accumulator(round(sqrt(pow(IMrows,2)+pow(IMcols,2))),0);//vector with the size of the diagonal in pixels each vector position is the size of minor axis-1
                std::vector<std::vector<unsigned>> accumulatorPoints;//vector of vectors with all the indices of the point that belong to the corresponding minor axis and ellips
                accumulatorPoints.resize(accumulator.size());

                const cv::Point &CurrentPixel=Pixels.at(CPI);
                //std::cout<<"CPI"<<CurrentPixel<<std::endl;

                if(!Pointsonellips.count(CPI) && getDist(PrimaryPixel,CurrentPixel)>=thresholdstep4)//check if CP is not already on ellips && check if dist>thershold
                {
                    cv::Point Center=getCenter(PrimaryPixel,CurrentPixel);

                    for(unsigned OPI=0;OPI<Pixels.size();++OPI)//OPI other pixel index
                    {
                        const cv::Point &OtherPixel=Pixels.at(OPI);
                        if(OPI!=CPI&&OPI!=PPI&&!Pointsonellips.count(OPI)&&getDist(Center,OtherPixel)>=thresholdstep6)
                        {
                            //std::cout<<"OPI:"<<OtherPixel<<std::endl;
                            double MA=getHalflengthMaA(PrimaryPixel,CurrentPixel);
                            //double oriantation=getOrientation(PrimaryPixel,CurrentPixel);
                            unsigned MiA=static_cast<unsigned>(round(getHalflengthMiA(MA,Center,CurrentPixel,OtherPixel)));
                            if(MiA>0&&MiA<(accumulator.size()-1))
                            {
                                ++accumulator.at(MiA-1);
                                (accumulatorPoints.at(MiA)).push_back(OPI);
                            }

                        }
                    }
                }

                //finding maximum element in accumulator
                std::vector<unsigned>::const_iterator itermax=max_element(accumulator.begin(),accumulator.end());
                if(*itermax>=thresholdstep10)
                {
                    unsigned b=itermax-accumulator.begin()+1;
                    //adding points of new ellips to pointsonellips set
                    Pointsonellips.insert((accumulatorPoints.at(b-1)).begin(),(accumulatorPoints.at(b-1)).end());
                    Pointsonellips.insert(PPI);
                    Pointsonellips.insert(CPI);
                    //adding ellips to output variables
                    ellipsCenters.push_back(getCenter(PrimaryPixel,CurrentPixel));
                    ellipshMA.push_back(static_cast<unsigned>(round(getHalflengthMaA(PrimaryPixel,CurrentPixel))));
                    ellipshMI.push_back(b);
                    ellipsoriantations.push_back(getOrientation(PrimaryPixel,CurrentPixel));

//                    std::cout<<"max="<<*itermax<<std::endl;
//                    std::cout<<"a="<<getHalflengthMaA(PrimaryPixel,CurrentPixel)<< std::endl;
//                    std::cout<<"b="<<itermax-accumulator.begin()+1<<std::endl;
//                    std::cout<<"center="<<getCenter(PrimaryPixel,CurrentPixel)<<std::endl;
                }


            }

        }

    }

}

void Ellipsfinder::getEllipses(std::vector<cv::Point> &Centers, std::vector<unsigned> &hMA, std::vector<unsigned> &hMI, std::vector<double> &oriantation)
{
    Centers=ellipsCenters;
    hMA=ellipshMA;
    hMI=ellipshMI;
    oriantation=ellipsoriantations;
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
    return atan((Ptwo.y-Pone.y)/(Ptwo.x-Pone.x));
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

