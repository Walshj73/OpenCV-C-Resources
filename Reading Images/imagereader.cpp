// Import the required libraries.
#include "ImageReader.h"
#include <iostream>

// Class constructor.
ImageReader::ImageReader() {}

// Class deconstructor.
ImageReader::~ImageReader() {}

// Read in an image.
cv::Mat ImageReader::readImage(cv::String fileDir)
{
    cv::Mat image;
    image = cv::imread(fileDir, cv::IMREAD_COLOR);

    if(!image.data)
    {
        std::cout << "Could not open or find the image" << "\n";
        exit(-1);
    }

    return image;
}

std::vector<cv::Mat> ImageReader::readImages(cv::String fileDir)
{
    std::vector<cv::String> fileName;
    std::vector<cv::Mat> images;

    cv::glob(fileDir, fileName, true);

    for(size_t k = 0; k < fileName.size(); ++k)
    {
        cv::Mat image = cv::imread(fileName[k], cv::IMREAD_COLOR);

        if(image.empty()) continue;

        if(!image.data)
        {
            std::cout << "Could not open or find the image" << "\n";
            exit(-1);
        }

        images.push_back(image);
    }

    return images;
}

// Display an image to the screen.
void ImageReader::displayImage(cv::Mat image)
{
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display image", image);
    cv::waitKey(0); 
}

// Display a single image from a vector.
void ImageReader::displayImages(std::vector<cv::Mat> images, int pos)
{
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display image", images.at(pos));
    cv::waitKey(0); 
}
