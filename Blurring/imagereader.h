#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <opencv2/opencv.hpp>
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

        // Adding a blur to the images.
        cv::Mat gaussianBlur(cv::Mat, const int);
        std::vector<cv::Mat> gaussianBlurs(std::vector<cv::Mat>, const int);
        cv::Mat medBlur(cv::Mat, const int);
        std::vector<cv::Mat> medBlurs(std::vector<cv::Mat>, const int);

        // Display the images.
        void displayImage(cv::Mat);
        void displayImages(std::vector<cv::Mat>, int pos);
};

#endif
