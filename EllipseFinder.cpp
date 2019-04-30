
#include "EllipseFinder.h"

EllipseFinder::EllipseFinder(const Mat Object)
	{
	

	
	};


EllipseFinder::~EllipseFinder() //Destructor
	{

	}; 


EllipseFinder::vector<Point> thresholdEllipse( int threshold ) 
{

vector<Point> coordinates; 

for(int i=1; i <= image.cols; i++)
{
	for( int j = 1; j<= image.rows; j++)
	{
		if (image.at<uchar>(Point(i,j)) == 255)
		{
			coordinates.push_back(Point(i,j));	
		}
	}
}


}			


};
