

#include "ellipseimage.h"

// Constructor
EllipseImage::EllipseImage(int xpix, int ypix) 
: 	image(ypix, xpix, CV_8UC1, cv::Scalar(0)), 
	colourimage(ypix, xpix, CV_8UC3, cv::Scalar(0, 0, 0)) 
{
	if ((xpix <= 0) || (ypix <= 0))
	{
		throw std::invalid_argument("Invalid input in: Image::Image \n Image pixel range must be larger than 0!");
	} 	
}

// Destructor
EllipseImage::~EllipseImage()
{
}


// ShowImage displays the (coloured) image in a new window
void EllipseImage::ShowImage()
{
	if ( !image.data )
    	{
        	printf("No image data \n");
    	}
    	cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
 	cv::imshow("Display Image", colourimage);
	cv::waitKey(0);
}

/*
DrawColouredEllipse draws a blue coloured ellipse with a red center location on a black background (Cartesian coordinate system --> origin left bottom)
	cenx: x-coordinate of the center
	ceny: y-coordinate of the center
	aaxis: the long axis of the ellipse
	baxis: the short axis of the ellipse
	xangle: the angle (in radians) between the x-axis and the long axis of the ellipse
	Npoints: the number of signal points forming the ellipse
*/
void EllipseImage::DrawColouredEllipse(int cenx, int ceny, int aaxis, int baxis, double xangle)
{	
	if ((cenx - image.cols > 0) || (ceny - image.cols > 0))
	{
		throw std::invalid_argument("Invalid input in: Image::DrawColouredEllipse \n Input coordinates must be located inside image!");
	}

	if ((aaxis < 1) || (baxis < 1))
	{
		throw std::invalid_argument("Invalid input in: Image::DrawColouredEllipse \n Long axis and short axis lengths must be positive integers!");
	}


	
	

	double pi = 3.14159265359;
	xangle = 2 * pi - xangle;
	
	// Drawing the ellipse 
	ellipse(colourimage, cv::Point(cenx, fabs(ceny - colourimage.rows)), cv::Size(aaxis, baxis), xangle * 180 / pi, 0, 360, cv::Scalar(255, 0, 0), 2);

	// Drawing the center
	circle(colourimage, cv::Point(cenx, fabs(ceny - colourimage.rows)), 3, cv::Scalar(0, 0, 255), -1);
}

/* 
DrawEllipse draws a white ellipse on a black background (Cartesian coordinate system --> origin left bottom)
	cenx: x-coordinate of the center
	ceny: y-coordinate of the center
 	aaxis: the long axis of the ellipse
 	baxis: the short axis of the ellipse
	xangle: the angle (in radians) between the x-axis and the long axis of the ellipse
 	Npoints: the number of signal points forming the ellipse
*/

void EllipseImage::DrawEllipse(int cenx, int ceny, int aaxis, int baxis, double xangle,  int Npoints, int &outpoints)
{
    outpoints = 0;
	if ((cenx - image.cols > 0) || (ceny - image.cols > 0))
	{
		throw std::invalid_argument("Invalid input in: Image::DrawEllipse \n Input coordinates must be located inside image!");
	}

	if ((aaxis < 1) || (baxis < 1))
	{
		throw std::invalid_argument("Invalid input in: Image::DrawEllipse \n Long axis and short axis lengths must be positive integers!");
	}

		

	if (Npoints < 3)
	{
		throw std::invalid_argument("Invalid input in: Image::DrawEllipse \n Number of points must be at least 3");
	}
	
	// Drawing the ellipse 

	double pi = 3.14159265359;
	double theta_step = 2 * pi / Npoints;
	xangle = 2 * pi - xangle;
	for (int i = 0; i < Npoints; i++)
	{
		
		// Calculating (x, y) couples for ellipse points with given a axis and b axis of the ellipse
		double x = cenx + aaxis * cos(i * theta_step);
		double y = ceny + baxis * sin(i * theta_step);
		
		// Rotating ellipe with respect to x-axis
		double xrot = (x-cenx) * cos(xangle) + (y-ceny) * sin(xangle) + cenx;
		double yrot = (y-ceny) * cos(xangle) - (x-cenx) * sin(xangle) + ceny;



        	if ((xrot >= 0) && (xrot <= image.cols) && (yrot >= 0) &&  (yrot <= image.rows))
		{
			image.at<uchar>(cv::Point(xrot , fabs(yrot - colourimage.rows) )) = 255;
        }else{
             outpoints++;
        }
		
	}

	cv::Mat tempim = image.clone();
	cv::cvtColor(tempim, tempim, CV_GRAY2BGR, 3);
 	colourimage += tempim;
}


// DrawNoise draws given number of noise points on the image
void EllipseImage::DrawNoise(int Noisepoints)
{

	if (Noisepoints <= 0)
	{
		throw std::invalid_argument("Invalid input in: Image::DrawNoise \n Number of noise points must be at least 1!");
	}
	cv::RNG rng(cv::getCPUTickCount());
	
	for (int i = 1; i <= Noisepoints; i++)
	{
		int locx = rng.uniform(0, image.cols);
		int locy = rng.uniform(0, image.rows);
		image.at<uchar>(cv::Point(locx, locy)) = 255;
	}
	cv::Mat tempim = image.clone();
	cv::cvtColor(tempim, tempim, CV_GRAY2BGR, 3);
	colourimage += tempim;
}

// GetImage returns the image to the user as a cv::Mat object
const cv::Mat EllipseImage::GetImage() const
{
	return image;
}

// GetColourImage returns the coloured image to the user as a cv::Mat object
const cv::Mat EllipseImage::GetColourImage() const
{
	return colourimage;
}

// ClearImage resets the cv::Mat object to a single channel black image
void EllipseImage::ClearImage()
{
	image = cv::Mat::zeros(image.size(), CV_8UC1);
}

// ClearColourImage resets the cv::Mat object to a three channel black image
void EllipseImage::ClearColourImage()
{
	colourimage = cv::Mat::zeros(colourimage.size(), CV_8UC3);
}





