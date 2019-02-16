#include "opencv2/opencv.hpp"

using namespace cv;
int main(int, char**){
    VideoCapture cap(0);
    Mat edges;
    namedWindow("edges", 1);
    for(;;){
        Mat frame;
        cap>>frame;
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges,edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges",edges);
        if(waitKey(10) == 27) break;
    }
    return 0;
}