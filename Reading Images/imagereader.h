#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <opencv2/highgui.hpp>
#include <vector>

class ImageReader
{
    public:
        ImageReader();
        ~ImageReader();
        cv::Mat readImage(cv::String);
        std::vector<cv::Mat> readImages(cv::String);
        void displayImage(cv::Mat);
        void displayImages(std::vector<cv::Mat>, int pos);
};

#endif
