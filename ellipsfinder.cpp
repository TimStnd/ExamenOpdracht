#include "ellipsfinder.h"


Ellipsfinder::Ellipsfinder(cv::Mat inputimage)
{
    std::vector<cv::Point> pixels;
    for(int r=0;r<inputimage.rows;++r)
    {
        for(int c=0;c<inputimage.cols;++c)
        {
            if(inputimage.at<uchar>(r,c)==255)
            {
                cv::Point coord(c,r);
                pixels.push_back(coord);
            }

        }
    }
    std::cout<<pixels.size()<<std::endl;
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
    return atan((Ptwo.y-Pone.x)/(Ptwo.x-Pone.x));
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

double Ellipsfinder::getHalflengthMiAsquared(const double a, const cv::Point &Pzero, const cv::Point &Ptwo, const cv::Point &Prandom) const
{
    double d=getDist(Pzero,Prandom);
    double costau=getCosTau(a, Pzero, Ptwo, Prandom);
    double sintau=sin(acos(costau));
    return (pow(a,2)*pow(d,2)*pow(sintau,2))/(pow(a,2)-pow(d,2)*pow(costau,2));
}
