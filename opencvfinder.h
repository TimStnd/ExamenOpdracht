#ifndef OPENCVFINDER_H
#define OPENCVFINDER_H
//OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
//STD
#include <vector>
#include <iostream>
#include <cmath>

class opencvfinder
{
public:
    opencvfinder(cv::Mat inputimage);
    void getelips(int threshold);
private:
    cv::Mat image;


};

#endif // OPENCVFINDER_H
