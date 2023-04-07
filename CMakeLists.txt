cmake_minimum_required(VERSION 3.23)
project(font-loader)

## find packages
find_package( OpenCV REQUIRED )

## add sub directories
add_subdirectory(external)
include_directories(include ui ${OpenCV_INCLUDE_DIRS})

## create executables and link
set(SOURCES src/glad.c
	    src/image_proc.cpp 
	    src/font_loader.cpp
            include/shader.h
            include/glad/glad.h
            include/KHR/khrplatform.h
            include/stb_image_write.h
	    include/image_proc.h
	    include/font_loader.h
            )

add_executable(${PROJECT_NAME}
    ${SOURCES}
)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    glfw
    freetype
)
