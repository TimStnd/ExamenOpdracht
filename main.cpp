//<<<<<<< HEAD
//Joshua Claes
//joshua.claes@student.uantwerpen.be
//datum: 22/04/2019
//STL
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iomanip>

//OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
//my headers
#include "ellipsfinder.h"


int main(int argc, char *argv[])
{
    Mat image(256,256, CV_8UC1, Scalar(0));
    image.at<uchar>(20,20)=255;
    image.at<uchar>(20,50)=255;
    image.at<uchar>(20,60)=255;
    image.at<uchar>(50,20)=255;

    image.at<uchar>(25,20)=25;

    Ellipsfinder test(image);





    return 0;
}



