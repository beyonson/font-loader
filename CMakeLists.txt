cmake_minimum_required(VERSION 3.23)
project(font-loader)

## find packages
find_package( OpenCV REQUIRED )
find_package( Qt6 REQUIRED COMPONENTS Widgets)
find_package( Qt6 REQUIRED COMPONENTS Gui)
find_package( Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

## add sub directories
add_subdirectory(external)
include_directories(include ui ${OpenCV_INCLUDE_DIRS})

## create executables and link
set(SOURCES src/glad.c
	    src/image_proc.cpp 
	    src/circular_progress.cpp
	    src/ui_main.cpp
            include/shader.h
            include/glad/glad.h
            include/KHR/khrplatform.h
            include/stb_image_write.h
	    include/image_proc.h
	    include/circular_progress.h
	    src/main_window.h
	    src/main_window.cpp
	    src/ui_typewriter.h
	    src/ui_splash_screen.h
            )

add_executable(${PROJECT_NAME}
    ${SOURCES}
)
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    glfw
    freetype
)
