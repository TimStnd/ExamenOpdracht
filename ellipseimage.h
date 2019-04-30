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
	
    const void DrawEllipse(int, int, int, int, double, int);
	const void DrawColouredEllipse(int, int, int, int, double);
	const void DrawNoise(int);
	const void ShowImage();
	const cv::Mat GetImage();
	const cv::Mat GetColourImage();
	const void ClearImage();
	const void ClearColourImage();


};

#endif 
