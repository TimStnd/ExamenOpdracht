

#include "opencvfinder.h"

using namespace cv;
using namespace std;
opencvfinder::opencvfinder(cv::Mat inputimage)
{
  image=inputimage;
}


vector<float> opencvfinder::getelips(int threshold)
{
    struct timespec start, end;

       vector<vector<Point> > contours;
       Mat bimage = image >= threshold;

       findContours(bimage, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

        vector<float> data;
       //clock_gettime(CLOCK_REALTIME, &start);

       for(size_t i = 0; i < contours.size(); i++)
       {
           size_t count = contours[i].size();
           if( count < 6 )
               continue;

           Mat pointsf;
           Mat(contours[i]).convertTo(pointsf, CV_32F);

           RotatedRect box = fitEllipse(pointsf);

           ;
      //*// DATA OUTPUT
           data.push_back(box.center.x);
           data.push_back(box.center.y);

           if(box.size.width<box.size.height)
           {
               data.push_back(box.size.height);
               data.push_back(box.size.width);
           } else{
               data.push_back(box.size.width);
               data.push_back(box.size.height);
           }

           if(box.angle>90)
           {
                data.push_back(((270-box.angle)/180)*3.14159265);
           } else{
                data.push_back(((90-box.angle)/180)*3.14159265);
           }
           cout<<"hier"<<endl;
       }
    return data;
}
