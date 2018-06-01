## build CMakeList of the thidrparty.a
cmake_minimum_required(VERSION 3.0.0)
project(thirdparty_arm)

# c++11 required
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#TODO:告知当前使用的是交叉编译方式，必须配置
SET(CMAKE_SYSTEM_NAME Linux)

#TODO:指定C交叉编译器，必须配置 TODO:或交叉编译环境器使用绝对地址。
SET(CMAKE_C_COMPILER "/opt/hisi-linux/x86-arm/arm-histbv310-linux/bin/arm-histbv310-linux-gcc")

#TODO:指定C++交叉编译器，必须配置 TODO:或交叉编译环境器使用绝对地址。
SET(CMAKE_CXX_COMPILER "/opt/hisi-linux/x86-arm/arm-histbv310-linux/bin/arm-histbv310-linux-gcc")

#TODO:添加头文件路径
include_directories(.)
include_directories("/work/gaohui/install/include/opencv")
include_directories("/work/gaohui/install/include")

#TODO:添加opencv动态链接库路径
LINK_DIRECTORIES("/work/gaohui/install/lib")

# OpenVC3 required
#find_package(OpenCV 3.1.0 REQUIRED)

#TODO: ds add 
#set(CV_INCLUDE_DIRS 
#            -I/home/ds/build/opencv-3.1.0/install/include
#            -I/home/ds/build/opencv-3.1.0/install/include/opencv
#)

# where to find header files
#include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories(${CV_INCLUDE_DIRS})

# sources to be compiled
set(SOURCE_FILES
        xmlParser/xmlParser.cpp
        textDetect/erfilter.cpp
        LBP/helper.cpp
        LBP/lbp.cpp
        mser/mser2.cpp
        )

# pack objects to static library
add_library(thirdparty_arm STATIC ${SOURCE_FILES})