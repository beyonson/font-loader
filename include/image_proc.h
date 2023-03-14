#ifndef IMAGE_PROC_H
#define IMAGE_PROC_H

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class ImageProc
{
    public:
        void ipSave(std::string filepath, GLFWwindow* w, int x, int y, int charWidth, int charHeight);
        int ipThreshold(std::string filepath, bool inverse);
        //void ipSkeletonize(std::string filepath);

    private:
        int threshold_value = 100;
        int threshold_type = 3;
        int const max_value = 255;
        int const max_type = 4;
        int const max_binary_value = 255;
};

#endif // IMAGE_PROC_H