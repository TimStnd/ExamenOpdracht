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
#include <cstdlib>
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

    unsigned xcenter=128;
    unsigned ycenter=128;
    unsigned a=100;
    unsigned b=50;
    unsigned alfa=0.;
    unsigned points=500;
    if(argc>=7)
    {
        xcenter=atoi(argv[1]);
        ycenter=atoi(argv[2]);
        a=atoi(argv[3]);
        b=atoi(argv[4]);
        alfa=atoi(argv[5]);
        points=atoi(argv[6]);
    }
    double angle=CV_PI*static_cast<double>(alfa)/180.;
    cout<< xcenter <<" " <<ycenter <<" "<< a <<" "<<b<<" "<<angle<<" "<<points<<endl;

    EllipseImage testdrawing(256,256);
    testdrawing.DrawEllipse(xcenter,ycenter,a,b,angle,points);
    Mat imagetestdrawing= testdrawing.GetImage();
    testdrawing.ShowImage();

    cout<<"Program is running"<<endl;
    Ellipsfinder test(imagetestdrawing);

    vector<Point> centers;
    vector<unsigned> MA;
    vector<unsigned> MI;
    vector<double> ori;
    test.getEllipses(centers,MA,MI,ori,50,10,100);
    for(unsigned i=0;i<centers.size();++i)
    {
        cout<<"center:"<<centers.at(i)<<endl;
        cout<<"MA:"<<MA.at(i)<<endl;
        cout<<"MI:"<<MI.at(i)<<endl;
        cout<<"oriantation:"<<ori.at(i)<<endl;
    }




    return 0;
}



