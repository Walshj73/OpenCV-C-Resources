#include "imagereader.h"
#include <iostream>

int main(int argc, char** argv)
{
    cv::String path {"../Images/*.jpg"};
    std::vector<cv::Mat> images;
    std::vector<cv::Mat> newImages;
    std::vector<cv::Mat> blurredImages;
    const int IMG_SIZE {128};
    int pos {2};

    ImageReader reader;
    images = reader.readImages(path);
    newImages = reader.resizeImages(images, IMG_SIZE);
    blurredImages = reader.medBlurs(newImages, 8);
    reader.displayImages(blurredImages, pos);

    return 0;
}
