#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <shader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void initTextbox();
void initCharbox();
void getKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);
void renderLastChar(Shader &s, std::string text, glm::vec3 color, GLFWwindow* window);
void RenderText(Shader &s, std::string text, float x, float y, float scale, glm::vec3 color, GLFWwindow* window);
bool loadChars(const char* filepath);
void saveImage(std::string filepath, GLFWwindow* w, int x, int y, int advanceX, int advanceY);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// create character struct
struct Character {
    unsigned int TextureID;
    glm::ivec2   Size;
    glm::ivec2   Bearing;
    unsigned int AdvanceX;
};
std::map<char, Character> Characters;

// create memory management objects
unsigned int textVBO, textVAO;
unsigned int charVBO, charVAO, charEBO;
unsigned int VAO, VBO, EBO;
std::string typedText = "";

int main()
{
    // initialize glfw and set version
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create glfw window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Text Editor", NULL, NULL);
    if (window == NULL) {
        std::cout << "ERROR: GLFW: Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ERROR: GLAD: Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // tell OpenGL size of window
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // initialize text box
    Shader ourShader("../shaders/shader.vs", "../shaders/shader.fs");
    initTextbox();
    initCharbox();

    // start doing text stuff

    // enable blending for text rendering and create projection matrix
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Shader textShader("../shaders/text.vs", "../shaders/text.fs");
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(SCR_WIDTH), 0.0f, static_cast<float>(SCR_HEIGHT));
    textShader.use();
    glUniformMatrix4fv(glGetUniformLocation(textShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

    // load font
    if (loadChars("../fonts/LiberationMono-Regular.ttf")) {
        return -1;
    }

    // create objects for the text
    glGenVertexArrays(1, &textVAO);
    glGenBuffers(1, &textVBO);
    glBindVertexArray(textVAO);
    glBindBuffer(GL_ARRAY_BUFFER, textVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*6*4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // set key press callbackcharacter
    glfwSetKeyCallback(window, getKeyPressed);

    // call render loop
    while(!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // set shader program
        ourShader.use();

        // rendering commands
        glClearColor(0.41f, 0.16f, 0.13f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw text box
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // draw char box
        glBindVertexArray(charVAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, charEBO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 

        // draw text
        RenderText(textShader, typedText, 82.0f, 492.0f, 0.2f, glm::vec3(0.5f, 0.5f, 0.5f), window);

        // render char
        if (typedText.length())
            renderLastChar(textShader, typedText, glm::vec3(0.5f, 0.5f, 0.5f), window);

        // check and call events and swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void initTextbox()
{
    // create vertex coordinates
    float vertices[] = {
        // positions        // colors
        -0.8f, -0.8f, 0.0f, 0.5f, 0.0f, 0.0f,   // bottom right
         0.8f, -0.8f, 0.0f, 0.5f, 0.0f, 0.0f,   // bottom left
        -0.8f,  0.8f, 0.0f, 0.5f, 0.0f, 0.0f,   // top
         0.8f,  0.8f, 0.0f, 0.5f, 0.0f, 0.0f    // top
    };

    // create rectangle
    unsigned int indices[] = {
        0, 1, 2,
        1, 3, 2
    };

    // create array object, buffer object, element object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // create buffer object and assign vertex data
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // create element buffer object and assign indices
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // tell OpenGL how to interpret vertex data
    // data, size (of attribute), type, normalize, stride (space b/w attributes), offset from beginning of data
    //
    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void initCharbox()
{
    // create vertex coordinates
    float vertices[] = {
        // positions        // colors
         0.5f,  -0.8f, 0.0f, 0.5f, 0.2f, 0.0f,   // bottom left
         0.95f, -0.8f, 0.0f, 0.5f, 0.2f, 0.0f,   // bottom right
         0.5f, -0.03f, 0.0f, 0.5f, 0.2f, 0.0f,   // top left
         0.95f,-0.03f, 0.0f, 0.5f, 0.2f, 0.0f    // top right
    };

    // create rectangle
    unsigned int indices[] = {
        0, 1, 2,
        1, 3, 2
    };

    // create array object, buffer object, element object
    glGenVertexArrays(1, &charVAO);
    glBindVertexArray(charVAO);

    // create buffer object and assign vertex data
    glGenBuffers(1, &charVBO);
    glBindBuffer(GL_ARRAY_BUFFER, charVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // create element buffer object and assign indices
    glGenBuffers(1, &charEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, charEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // tell OpenGL how to interpret vertex data
    // data, size (of attribute), type, normalize, stride (space b/w attributes), offset from beginning of data
    //
    // position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void RenderText(Shader &s, std::string text, float x, float y, float scale, glm::vec3 color, GLFWwindow* window)
{
    // activate corresponding render state	
    s.use();
    glUniform3f(glGetUniformLocation(s.ID, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(textVAO);

    // iterate through all characters
    std::string::const_iterator c;
    std::string fileName;
    int advanceX;
    for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = Characters[*c];

        float xpos = x + ch.Bearing.x * scale;
        float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;
        // update VBO for each character
        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },            
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }           
        };
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, textVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.AdvanceX >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64)
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void renderLastChar(Shader &s, std::string text, glm::vec3 color, GLFWwindow* window)
{
    // activate corresponding render state	
    s.use();
    glUniform3f(glGetUniformLocation(s.ID, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(textVAO);

    // iterate through all characters
    if (text.length())
    {
        unsigned int charCount = 0;
        int advanceX;
        Character ch = Characters[text[text.length() - 1]];

        float xpos = 605.0f;
        float ypos = 65.0f;
        float scale= 1;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;
        // update VBO for each character
        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },            
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }           
        };
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, textVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // save image of character
        std::string fileName = "../chars/ss" + std::to_string(text.length()) + ".png";
        advanceX = (ch.AdvanceX >> 6) * scale;
        saveImage(fileName, window, xpos-2, ypos-2, advanceX, 230);
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

bool loadChars(const char* filepath)
{
    // initialize Freetype and load font
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        std::cout << "ERROR: FREETYPE: Failed to initialize FreeType" << std::endl;
        return 1;
    }

    // create and load face
    FT_Face face;
    if (FT_New_Face(ft, filepath, 0, &face)) {
        std::cout << "ERROR: FREETYPE: Failed to load font face" << std::endl;
        return 1;
    }

    // set size to load glyphs as
    FT_Set_Pixel_Sizes(face, 0, 300);
    
    for (unsigned char c = 0; c < 128; c++)
    {
        // load character glyph 
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }
        // generate texture
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
        // set texture options
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // now store character for later use
        Character character = {
            texture, 
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            static_cast<unsigned int>(face->glyph->advance.x)
        };
        Characters.insert(std::pair<char, Character>(c, character));
    }
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    return 0;
}

void saveImage(std::string filepath, GLFWwindow* w, int x, int y, int charWidth, int charHeight) 
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

void getKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_RELEASE)
        typedText += key;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}