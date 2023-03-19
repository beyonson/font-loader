#ifndef IMAGE_PROC_H
#define IMAGE_PROC_H

#include <opencv2/imgproc.hpp>
#include <opencv2/ximgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class ImageProc
{
    public:
        void ipSave(std::string filepath, GLFWwindow* w, int x, int y, int charWidth, int charHeight);
        void ipSave(std::string dstpath, int x, int y, GLubyte* pixels);
        int ipThreshold(std::string srcpath, std::string dstpath, bool inverse);
        int ipSkeletonize(std::string srcpath, std::string dstpath);
        //int ipProcessChar(std::string srcpath, std::string dstpath);
        //int ipSkeletonize(Mat src, std::string dstpath);

    private:
        int threshold_value = 0;
        int threshold_type = 4;
        int const max_value = 255;
        int const max_type = 4;
        int const max_binary_value = 255;
};

#endif // IMAGE_PROC_H