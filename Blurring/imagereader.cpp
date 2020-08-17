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

// Apply a gaussian blur to a single image.
cv::Mat ImageReader::gaussianBlur(cv::Mat image, const int KERNEL_SIZE)
{
    cv::Mat dst;
    for(size_t k = 1; k < KERNEL_SIZE; k = k + 2)
    {
        cv::GaussianBlur(image, dst, cv::Size(k, k), 0, 0);
    }
    return dst;
}

// Apply a gaussian blur to all the images.
std::vector<cv::Mat> ImageReader::gaussianBlurs(std::vector<cv::Mat> images, const int KERNEL_SIZE)
{
    std::vector<cv::Mat> blurredImages;
    for(size_t k = 0; k < images.size(); ++k)
    {
        cv::Mat dst;

        for(size_t i = 1; i < KERNEL_SIZE; i = i + 2)
        {
            cv::GaussianBlur(images[k], dst, cv::Size(i, i), 0, 0);
        }

        if(dst.empty())
        {
            continue;
        }
        blurredImages.push_back(dst);
    }
    return blurredImages;
}

// Apply a median blur to a single image.
cv::Mat ImageReader::medBlur(cv::Mat image, const int KERNEL_SIZE)
{
    cv::Mat dst;
    for(size_t k = 1; k < KERNEL_SIZE; k = k + 2)
    {
        cv::medianBlur(image, dst, k);
    }
    return dst;
}

// Apply a median blur to all the images.
std::vector<cv::Mat> ImageReader::medBlurs(std::vector<cv::Mat> images, const int KERNEL_SIZE)
{
    std::vector<cv::Mat> blurredImages;
    for(size_t k = 0; k < images.size(); ++k)
    {
        cv::Mat dst;
        for(size_t i = 1; i < KERNEL_SIZE; i = i + 2)
        {
            cv::medianBlur(images[k], dst, i);
        }

        if(dst.empty())
        {
            continue;
        }
        blurredImages.push_back(dst);
    }
    return blurredImages;
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
