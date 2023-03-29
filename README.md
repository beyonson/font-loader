# OpenGL Text Editor

### About

Simple text editor implemented in OpenGL with FreeType, for the purpose of skeletonizing typed text.

### Dependencies

This project was built and tested with the following versions

* FreeType 2.13.0
* GLFW 3.3.8
* OpenGL 3.3
* OpenCV 4.7
* OpenCV contrib 4.x

### Installation

First, clone the repository:
```
$ git clone git@github.com:beyonson/font-loader.git
```

Then, change directories into the project, and initialize submodules:
```
$ cd font-loader
$ git submodule update --init --recursive
```

Go to the build directory and run CMake and Make:
```
$ cd build
$ cmake ..
$ make
```

### Usage

After building run
```
$ ./font-loader <font filepath>
```

Where font filepath is the font you want loaded
