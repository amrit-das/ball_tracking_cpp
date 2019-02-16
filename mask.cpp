#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int y=0,u=72,v=138;

using namespace cv;
using namespace std;

int main(int, char**){
    VideoCapture cap(0);
    Mat mask;
    RNG rng(12345);
    namedWindow("output",1);
    
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;  
    vector<Point2f>center( contours.size() );
    vector<float>radius( contours.size() );
    vector<vector<Point> > contours_poly( contours.size() );

    while(true){
        Mat frame;
        cap>>frame;

        cvtColor(frame, mask, COLOR_BGR2YUV);
        GaussianBlur(mask, mask, Size(7,7), 1.5, 1.5);
        inRange(mask, Scalar(0,u-30,v-30), Scalar(255, u+30, v+30),mask);
        
        findContours( mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point(0, 0));

        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        
        imshow("output",mask);
        if (waitKey(10) == 27) break;
    }
    return 0; 
}