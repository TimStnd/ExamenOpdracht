

#include "opencvfinder.h"

using namespace cv;
using namespace std;
opencvfinder::opencvfinder(cv::Mat inputimage)
{
  image=inputimage;
}


void opencvfinder::getelips(int threshold)
{
    struct timespec start, end;
        cout<<"test"<<endl;
       vector<vector<Point> > contours;
       Mat bimage = image >= threshold;

       findContours(bimage, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);


       //clock_gettime(CLOCK_REALTIME, &start);

       for(size_t i = 0; i < contours.size(); i++)
       {
           size_t count = contours[i].size();
           if( count < 6 )
               continue;

           Mat pointsf;
           Mat(contours[i]).convertTo(pointsf, CV_32F);

           RotatedRect box = fitEllipse(pointsf);

           cout<<"data"<<endl;
      //*// DATA OUTPUT
           cout << box.center << endl;
           cout << box.center.x <<endl;
           cout << box.angle << endl;
           cout << box.size << endl;
           cout << box.size.width <<endl;
      //*//
       }
}
