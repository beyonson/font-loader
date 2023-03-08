cmake_minimum_required(VERSION 3.25)
project(learn-opengl)

## add sub directories
add_subdirectory(external)
include_directories(include)

## create executables and link
set(SOURCES src/main.cpp src/glad.c include/shader.h include/glad/glad.h include/KHR/khrplatform.h)
add_executable(${PROJECT_NAME}
    ${SOURCES}
)
target_link_libraries(${PROJECT_NAME}
    glfw
    freetype
)
