#include "imagereader.h"
#include <iostream>

int main(int argc, char** argv)
{
    cv::String path {"../Images/*.jpg"};
    std::vector<cv::Mat> images;
    std::vector<cv::Mat> newImages;
    const int IMG_SIZE {128};
    int pos {0};

    ImageReader reader;
    images = reader.readImages(path);
    newImages = reader.resizeImages(images, IMG_SIZE);
    reader.displayImages(newImages, pos);
    
    return 0;
}
