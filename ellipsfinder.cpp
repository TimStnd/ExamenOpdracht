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

cv::Point Ellipsfinder::getCenter(const cv::Point &Pone, const cv::Point &Ptwo)
{
    double x0=static_cast<double>((Pone.x+Ptwo.x))/2;
    double y0=static_cast<double>((Pone.y+Ptwo.y))/2;
    cv::Point center(x0,y0);
    return center;
}

double Ellipsfinder::getHalflengthofMA(const cv::Point &Pone, const cv::Point &Ptwo)
{
    return sqrt(pow(Ptwo.x-Pone.x,2)+pow(Ptwo.y-Pone.y,2))/2;

}

double Ellipsfinder::getOrientation(const cv::Point &Pone, const cv::Point &Ptwo)
{
    return atan((Ptwo.y-Pone.x)/(Ptwo.x-Pone.x));
}
