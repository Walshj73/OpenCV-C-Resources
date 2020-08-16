// Import the required libraries.
#include "imagereader.h"
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

// Resize a vector of images.
std::vector<cv::Mat> ImageReader::readImages(cv::String fileDir)
{
    std::vector<cv::String> fileName;
    std::vector<cv::Mat> images;

    cv::glob(fileDir, fileName, true);
    for(size_t k = 0; k < fileName.size(); ++k)
    {
        cv::Mat image = cv::imread(fileName[k], cv::IMREAD_COLOR);

        if(image.empty())
        {
            continue;
        }

        if(!image.data)
        {
            std::cout << "Could not open or find the image" << "\n";
            exit(-1);
        }

        images.push_back(image);
    }

    return images;
}

// Resize a single image.
cv::Mat ImageReader::resizeImage(cv::Mat image, const int IMG_SIZE)
{
    cv::Mat dst;
    cv::resize(image, dst, cv::Size(IMG_SIZE, IMG_SIZE));
    return dst;
}

// Resize a vector of images.
std::vector<cv::Mat> ImageReader::resizeImages(std::vector<cv::Mat> images, const int IMG_SIZE)
{
    std::vector<cv::Mat> resizedImages;
    for(size_t k = 0; k < images.size(); ++k)
    {
        cv::Mat dst;
        cv::resize(images[k], dst, cv::Size(IMG_SIZE, IMG_SIZE));

        if(dst.empty())
        {
            continue;
        }

        resizedImages.push_back(dst);
    }
    return resizedImages;
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
