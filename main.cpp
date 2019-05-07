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
using namespace std;

//OpenCV
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
//Project headers
#include "ellipsfinder.h"
#include "ellipseimage.h"



int main(int argc, char *argv[])
{
    Mat image(256,256, CV_8UC1, Scalar(0));
    image.at<uchar>(20,20)=255;
    image.at<uchar>(20,50)=255;
    image.at<uchar>(20,60)=255;
    image.at<uchar>(50,20)=255;

    image.at<uchar>(25,20)=25;

    EllipseImage testdrawing(256,256);
    testdrawing.DrawEllipse(128,128,100,50,0,500);
    Mat imagetestdrawing= testdrawing.GetImage();
    //testdrawing.ShowImage();

    Ellipsfinder test(imagetestdrawing,50,1,100);

    vector<Point> centers;
    vector<unsigned> MA;
    vector<unsigned> MI;
    vector<double> ori;
    test.getEllipses(centers,MA,MI,ori);
    for(unsigned i=0;i<centers.size();++i)
    {
        cout<<"center:"<<centers.at(i)<<endl;
        cout<<"MA:"<<MA.at(i)<<endl;
        cout<<"MI:"<<MI.at(i)<<endl;
        cout<<"oriantation:"<<ori.at(i)<<endl;
    }




    return 0;
}



