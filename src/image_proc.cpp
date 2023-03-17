#include "../include/image_proc.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace cv;

void ImageProc::ipSave(std::string filepath, GLFWwindow* w, int x, int y, int charWidth, int charHeight)
{
    int width, height;

    glfwGetFramebufferSize(w, &width, &height);
    GLsizei nrChannels = 3;
    GLsizei stride = nrChannels * charWidth;
    stride += (stride % 4) ? (4 - stride % 4) : 0;
    GLsizei bufferSize = stride * charHeight;
    std::vector<char> buffer(bufferSize);
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    glReadBuffer(GL_FRONT);
    glReadPixels(x, y, charWidth, charHeight, GL_RGB, GL_UNSIGNED_BYTE, buffer.data());
    stbi_flip_vertically_on_write(true);

    char* fileName = new char[filepath.length() + 1];
    strcpy(fileName, filepath.c_str());
    stbi_write_png(fileName, charWidth, charHeight, nrChannels, buffer.data(), stride);
}

int ImageProc::ipThreshold(std::string srcpath, std::string dstpath, bool inverse)
{
    Mat src_gray, dst, src;
    src = imread(samples::findFile(srcpath), IMREAD_COLOR);
    if (src.empty())
    {
        std::cout << "Cannot read the image: " << srcpath << std::endl;
        return -1;
    }
    
    cvtColor(src, src_gray, COLOR_BGR2GRAY);
    threshold(src_gray, dst, threshold_value, max_binary_value, 0);
    imwrite(dstpath, dst);

    return 0;
}

int ImageProc::ipSkeletonize(std::string srcpath, std::string dstpath)
{
    Mat src, dst;
    src = imread(samples::findFile(srcpath), IMREAD_UNCHANGED);
    if (src.empty())
    {
        std::cout << "Cannot read the image: " << srcpath << std::endl;
        return -1;
    }

    ximgproc::thinning(src, dst, 0);
    imwrite(dstpath, dst);

    return 0;
}