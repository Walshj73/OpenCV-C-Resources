#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <opencv2/highgui.hpp>
#include <string>

class ImageReader
{
    private:
        std::string fileDir;
    public:
        // Constructor & deconstructor.
        ImageReader(std::string);
        ~ImageReader();

        // Read an image.
        cv::Mat readImage();

        // Display an image.
        void displayImage(cv::Mat);
};

#endif
