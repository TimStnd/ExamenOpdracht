//*******************************************************************************
//*
//*
//*  This program is demonstration for ellipse fitting. Program finds
//*  contours and approximate it by ellipses.
//*
//*  Trackbar specify threshold parametr.
//*
//*  White lines is contours. Red lines is fitting ellipses.
//*
//*
//*  Autor:  Denis Burenkov.
//*
//*
//*
//********************************************************************************/
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "ellipseimage.h"
using namespace cv;
using namespace std;

// static void help()
// {
//     cout <<
//             "\nThis program is demonstration for ellipse fitting. The program finds\n"
//             "contours and approximate it by ellipses.\n"
//             "Call:\n"
//             "./fitellipse [image_name -- Default stuff.jpg]\n" << endl;
// }

int threshold = 70;

Mat image;

void processImage(int, void*);


int main( int argc, char** argv )
{

//    EllipseImage sitfour(256,256);
//    sitfour.DrawEllipse(100,150,50,30,3.14,500);
//    sitfour.DrawEllipse;
//    image = sitfour.GetImage();

    const char* filename = argc == 2 ? argv[1] : (char*)"egg_boiled.jpg";
    Mat nonsized = imread(filename, 0);
    if( nonsized.empty() )
    {
        cout << "Couldn't open image " << filename << "\nUsage: fitellipse <image_name>\n";
        return 0;
    }

    resize(nonsized, image, Size(256,256), 0, 0, INTER_CUBIC);
    imshow("source", image);


    namedWindow("result", CV_WINDOW_AUTOSIZE);


    // Create toolbars. HighGUI use.
    createTrackbar( "threshold", "result", &threshold, 255, processImage );
    processImage(0, 0);

    // Wait for a key stroke; the same function arranges events processing
    waitKey();
    return 0;
}

// Define trackbar callback functon. This function find contours,
// draw it and approximate it by ellipses.
void processImage(int /*h*/, void*)
{
    struct timespec start, end;

    vector<vector<Point> > contours;
    Mat bimage = image >= threshold;

    findContours(bimage, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    Mat cimage = Mat::zeros(bimage.size(), CV_8UC3);

    cout << "Output\n";


    clock_gettime(CLOCK_REALTIME, &start);

    for(size_t i = 0; i < contours.size(); i++)
    {
        size_t count = contours[i].size();
        if( count < 6 )
            continue;

        Mat pointsf;
        Mat(contours[i]).convertTo(pointsf, CV_32F);

        RotatedRect box = fitEllipse(pointsf);


   //*//  DRAWING OUTPUT
        if( MAX(box.size.width, box.size.height) > MIN(box.size.width, box.size.height)*30 )
              continue;
        drawContours(cimage, contours, (int)i, Scalar::all(255), 1, 8);

        ellipse(cimage, box, Scalar(0,0,255), 1, CV_AA);
        ellipse(cimage, box.center, box.size*0.5f, box.angle, 0, 360, Scalar(0,255,255), 1, CV_AA);
        Point2f vtx[4];
        box.points(vtx);
        for( int j = 0; j < 4; j++ )
            line(cimage, vtx[j], vtx[(j+1)%4], Scalar(0,255,0), 1, CV_AA);
   //*// DATA OUTPUT
        //cout << "Output\n";
        cout << "center is "<< box.center << "\t a is  " << box.size.height << "b is " << box.size.width << " \t angle is " << box.angle << endl;
   //*//
    }
    clock_gettime(CLOCK_REALTIME, &end);

    long long unsigned int diff = end.tv_nsec - start.tv_nsec;
    std::cout << "Elapsed time :" << diff * std::pow(10,-9) << "s" << std::endl;


    imshow("result", cimage);

}
