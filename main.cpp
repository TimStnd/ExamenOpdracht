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
#include <time.h>
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
    unsigned minMA=20;
    unsigned minMI=10;
    unsigned th10=100;
    unsigned MIuni=0;
    if(argc>=5)
    {
        minMA=atoi(argv[1]);
        minMI=atoi(argv[2]);
        th10=atoi(argv[3]);
        MIuni=atoi(argv[4]);
    }
//        alfa=atoi(argv[5]);
//        points=atoi(argv[6]);
//    }
//    if(argc>=8)MIuni=atoi(argv[7]);
    double angle=CV_PI*static_cast<double>(alfa)/180.;
    cout<< xcenter <<" " <<ycenter <<" "<< a <<" "<<b<<" "<<angle<<" "<<points<<endl;

    EllipseImage testdrawing(256,256);
    testdrawing.DrawEllipse(xcenter,ycenter,a,b,angle,points);
    testdrawing.DrawEllipse(75,75,50,40,0,500);
    Mat imagetestdrawing= testdrawing.GetImage();
    testdrawing.ShowImage();

    cout<<"Program is running"<<endl;
    Ellipsfinder test(imagetestdrawing);

    vector<Point> centers;
    vector<unsigned> MA;
    vector<unsigned> MI;
    vector<double> ori;

    clock_t start,end;
    start=clock();
    test.getEllipses(centers,MA,MI,ori,minMA,minMI,th10,MIuni);
    end=clock();
    cout<< "my implementation takes: "<<std::setprecision(10) << static_cast<double>(end-start)/CLOCKS_PER_SEC*1E+3<< " milli seconds." << "\n\n";
    for(unsigned i=0;i<centers.size();++i)
    {
        cout<<"center:"<<centers.at(i)<<endl;
        cout<<"MA:"<<MA.at(i)<<endl;
        cout<<"MI:"<<MI.at(i)<<endl;
        cout<<"oriantation:"<<CV_PI-ori.at(i)<<endl;
    }




    return 0;
}



