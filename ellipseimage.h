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
	
    void DrawLine(int xstart, int ystart, int xend, int yend);
    void DrawEllipse(int, int, int, int, double, int &, int = 500);
    void DrawColouredEllipse(int, int, int, int, double);
    void DrawNoise(int);
    void ShowImage() const;
    const cv::Mat GetImage() const;
    const cv::Mat GetColourImage() const;
    void ClearImage();
    void ClearColourImage();
    void ReadImage(cv::Mat);


};

#endif 
