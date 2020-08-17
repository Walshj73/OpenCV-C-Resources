#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <opencv2/highgui.hpp>
#include <vector>

class ImageReader
{
    public:
        // Constructor & deconstructor.
        ImageReader();
        ~ImageReader();

        // Reading the images.
        cv::Mat readImage(cv::String);
        std::vector<cv::Mat> readImages(cv::String);

        // Resizing the images.
        cv::Mat resizeImage(cv::Mat, const int);
        std::vector<cv::Mat> resizeImages(std::vector<cv::Mat>, const int);
};

#endif
