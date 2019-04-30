#ifndef ELLIPSFINDER_H
#define ELLIPSFINDER_H
//OpenCV
#include <opencv2/opencv.hpp>
//STD
#include <vector>
#include <iostream>
#include <cmath>

class Ellipsfinder
{
public:
    Ellipsfinder(cv::Mat inputimage);
private:
    unsigned thresholdstep4;
    unsigned thresholdstep6;
    unsigned thresholdstep10;

    cv::Point getCenter(const cv::Point &Pone,const cv::Point &Ptwo);
    double getHalflengthofMA(const cv::Point &Pone,const cv::Point &Ptwo);//get half length of major axis
    double getOrientation(const cv::Point &Pone,const cv::Point &Ptwo);
//    double getCosTau(const double a,const double d,const double f);



};

#endif // ELLIPSFINDER_H
