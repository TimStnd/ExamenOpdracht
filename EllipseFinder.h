#ifndef ELLIPSEFINDER_H  
#define ELLIPSEFINDER_H

#include "Teken ellipse klasse"

using namespace std; 
using namespace cv; 

class EllipseFinder
{

	private:

		


	public:
		EllipseFinder(/*int, int, */ const Mat);  //Constructor
		~EllipseFinder(); 		      //Destructor 

		
		vector<Point> thresholdEllipse(int );  
		//int getMax(int ); 
		//void getImage();

}; 


#endif

