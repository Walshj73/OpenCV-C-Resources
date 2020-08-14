#include "ImageReader.h"
#include <iostream>

int main(int argc, char** argv)
{
    cv::String path {"../Images/*.jpg"};
    std::vector<cv::Mat> images;
    int pos {0};

    ImageReader reader;
    images = reader.readImages(path);
    reader.displayImages(images, pos);

    return 0;
}
