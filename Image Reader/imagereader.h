#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <opencv2/highgui.hpp>
#include <string>

class ImageReader
{
    private:
        std::string fileDir;
    public:
        ImageReader(std::string);
        ~ImageReader();
        cv::Mat readImage();
        void displayImage(cv::Mat);
};

#endif
