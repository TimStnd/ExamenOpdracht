#ifndef ELLIPSEIMAGE_H
#define ELLIPSEIMAGE_H

#include <stdio.h>
#include <opencv2/opencv.hpp>






class EllipseImage
{
private:
	cv::Mat image;
	cv::Mat colourimage;

public:
	EllipseImage(int = 256, int = 256); 		// constructor
	~EllipseImage(); 				//destructor
	
    void DrawEllipse(int, int, int, int, double, int, int &);
    void DrawColouredEllipse(int, int, int, int, double);
    void DrawNoise(int);
    void ShowImage();
    const cv::Mat GetImage() const;
    const cv::Mat GetColourImage() const;
    void ClearImage();
    void ClearColourImage();


};

#endif 
