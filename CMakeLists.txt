cmake_minimum_required(VERSION 3.23)
project(text-editor)

## find packages
find_package( OpenCV REQUIRED )
find_package( Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

## add sub directories
add_subdirectory(external)
include_directories(include ${OpenCV_INCLUDE_DIRS})

## create executables and link
set(SOURCES src/main.cpp 
            src/glad.c
	    src/image_proc.cpp 
	    src/window.cpp
            include/shader.h
            include/glad/glad.h
            include/KHR/khrplatform.h
            include/stb_image_write.h
	    include/image_proc.h
            )

add_executable(${PROJECT_NAME}
    ${SOURCES}
)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    Qt6::Widgets
    glfw
    freetype
)
