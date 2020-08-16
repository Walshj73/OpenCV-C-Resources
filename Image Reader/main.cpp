// Import the required libraries.
#include "imagereader.h"
#include <iostream>

// Main method.
int main(int argc, char** argv)
{
    std::string fileDir = "../Images/doggo.jpg";
    cv::Mat image;

    ImageReader reader (fileDir);
    image = reader.readImage();
    reader.displayImage(image);
    return 0;
}
