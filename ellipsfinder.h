#ifndef ELLIPSFINDER_H
#define ELLIPSFINDER_H
//OpenCV
#include <opencv2/opencv.hpp>
//STD
#include <vector>
#include <set>
#include <iostream>
#include <cmath>
#include <stdlib.h>

class Ellipsfinder
{
public:
    Ellipsfinder(cv::Mat inputimage,unsigned minhMA,unsigned minhMI, unsigned th10);
    void getEllipses(std::vector<cv::Point> &Centers,std::vector<unsigned> &hMA, std::vector<unsigned> &hMI, std::vector<double> &oriantation);
private:
    std::vector<cv::Point> ellipsCenters;
    std::vector<unsigned> ellipshMA;//hMA=half major axis
    std::vector<unsigned> ellipshMI;//hMI=half minor axis
    std::vector<double> ellipsoriantations;


    unsigned thresholdstep4;
    unsigned thresholdstep6;
    unsigned thresholdstep10;
    //unsigned minhMIerr;
    std::vector<cv::Point> Pixels;
    const unsigned IMrows;
    const unsigned IMcols;

    void Algoritm();

    //====================================Formulas from paper===========================
    //Pone(x1,y1) and Ptwo(x2,y2) are the same as on the paper
    //formula 1&2:
    cv::Point getCenter(const cv::Point &Pone,const cv::Point &Ptwo) const;
    //formula 3:
    //get half length of major axis
    double getHalflengthMaA(const cv::Point &Pone,const cv::Point &Ptwo) const;
    //formula 4:
    //Pzero is the middle of the ellips     randompoint is the random xy point that's on the ellips (see figure 1 paper)
    double getOrientation(const cv::Point &Pone,const cv::Point &Ptwo) const ;
    //formula 5:
    double getCosTau(const double a, const cv::Point &Pzero, const cv::Point &Ptwo, const cv::Point &Prandom) const;
    //formula 6:
    //get half length of minor axis
    double getHalflengthMiA(const double a, const cv::Point &Pzero, const cv::Point &Ptwo, const cv::Point &Prandom)const;
    //=================================================================================
    double getDist(const cv::Point &Pone,const cv::Point &Ptwo) const;//return distans between 2 points


};

#endif // ELLIPSFINDER_H
