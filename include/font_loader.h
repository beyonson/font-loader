#ifndef FONT_LOADER_H
#define FONT_LOADER_H

#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <string>
// import opengl libraries
#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// import freetype
#include <ft2build.h>
#include FT_FREETYPE_H
// import local
#include "image_proc.h"
#include "shader.h"
#include "circular_progress.h"

int loadFont(const char* FONTPATH);
bool loadChars(const char* filepath);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

#endif // FONT_LOADER_H