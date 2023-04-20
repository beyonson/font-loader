#include "font_loader.h"
#define FONTPATH argv[1]

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
const unsigned int CHARHEIGHT = 500;

// create memory management objects
unsigned int textVBO, textVAO;

// global vars
ImageProc imageProc;

int main(int argc, char *argv[])
{
    // initialize glfw and set version
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

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
        // initialize Freetype and load font
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        std::cout << "ERROR: FREETYPE: Failed to initialize FreeType" << std::endl;
        return 1;
    }

    // create and load face
    FT_Face face;
    if (FT_New_Face(ft, FONTPATH, 0, &face)) {
        std::cout << "ERROR: FREETYPE: Failed to load font face" << std::endl;
        return 1;
    }

    // set size to load glyphs as
    FT_Set_Pixel_Sizes(face, 0, 400);
    int width, height, advanceX;
    
    for (unsigned int c = 65; c < 91; c++)
    {
        // load character glyph 
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }
        // generate texture
        unsigned int texture, texture2;
        width = face->glyph->bitmap.width;
        height = face->glyph->bitmap.rows;
        advanceX = (face->glyph->advance.x >> 6) + 30;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            width,
            height,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );
        // set texture options
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glGenTextures(1, &texture2);
        glBindTexture(GL_TEXTURE_2D, texture2);

        // create larger empty rectangle
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            advanceX,
            CHARHEIGHT,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            NULL
        );
        // copy char texture into larger empty rectangle
        glTexSubImage2D(
            GL_TEXTURE_2D,
            0,
            (face->glyph->metrics.horiBearingX >> 6) + 15,
            (360 - (face->glyph->metrics.horiBearingY >> 6)), // 360 chosen arbitrarily as the y origin
            width,
            height,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );

        // bind new frame buffer
        unsigned int fbo;
        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture2, 0);

        // read char pixels from frame buffer
        unsigned int data_size = (advanceX) * CHARHEIGHT;
        GLubyte* pixels = new GLubyte[(advanceX) * CHARHEIGHT* 4];
        glReadPixels(0, 0, advanceX, CHARHEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        glDeleteFramebuffers(1, &fbo);

        std::string filename = "../chars/";
        filename += std::to_string(c);
        filename += ".bmp";

        imageProc.ipSave(filename, advanceX , CHARHEIGHT, pixels);
        imageProc.ipThreshold(filename, filename, true);
	imageProc.ipSkeletonize(filename, filename);
    }
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

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

    glfwTerminate();
    return 0;
}

bool loadChars(const char* filepath)
{
    return true;
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
