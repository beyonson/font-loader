cmake_minimum_required(VERSION 3.25)
project(opengl-text-editor)

## find packages
find_package( OpenCV REQUIRED )

## add sub directories
add_subdirectory(external)
include_directories(include ${OpenCV_INCLUDE_DIRS})

## create executables and link
set(SOURCES src/image_processing.cpp src/glad.c include/shader.h include/glad/glad.h include/KHR/khrplatform.h include/stb_image_write.h)
add_executable(${PROJECT_NAME}
    ${SOURCES}
)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    glfw
    freetype
)
