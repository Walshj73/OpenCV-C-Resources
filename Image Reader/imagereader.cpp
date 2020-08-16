// Import the required libraries.
#include "imagereader.h"
#include <iostream>

// Class constructor.
ImageReader::ImageReader(std::string fileDir):fileDir(fileDir) {}

// Class deconstructor.
ImageReader::~ImageReader() {}

// Read in an image.
cv::Mat ImageReader::readImage()
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

// Display an image to the screen.
void ImageReader::displayImage(cv::Mat image)
{
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display image", image);
    cv::waitKey(0); 
}
