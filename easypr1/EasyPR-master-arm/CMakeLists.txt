## build CMakeList of the executable file
cmake_minimum_required(VERSION 3.0.0)
project(easypr)

# c++11 required
#set(CMAKE_CXX_STANDARD 11)   #c++11标准也可以在这里设置
#set(CMAKE_CXX_STANDARD_REQUIRED ON)


#TODO:告知当前使用的是交叉编译方式，必须配置
SET(CMAKE_SYSTEM_NAME Linux)

#TODO:指定C交叉编译器，必须配置 TODO:或交叉编译环境器使用绝对地址。
SET(CMAKE_C_COMPILER "/opt/hisi-linux/x86-arm/arm-histbv310-linux/bin/arm-histbv310-linux-gcc")

#TODO:指定C++交叉编译器，必须配置 TODO:或交叉编译环境器使用绝对地址。
SET(CMAKE_CXX_COMPILER "/opt/hisi-linux/x86-arm/arm-histbv310-linux/bin/arm-histbv310-linux-g++")

#TODO :添加从c++11
add_compile_options(-std=c++11)

#if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
#  set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/local/opt/opencv3")
#endif ()

# OpenVC3 required
find_package(OpenCV 3.2.0 REQUIRED)

# where to find header files
include_directories(.)
include_directories(include)
#include_directories(${OpenCV_INCLUDE_DIRS})
#TODO:添加头文件路径
include_directories("/work/gaohui/install/include/opencv")
include_directories("/work/gaohui/install/include")

#TODO:添加opencv动态链接库路径
LINK_DIRECTORIES("/work/gaohui/install/lib")

# sub directories
add_subdirectory(thirdparty)

# sources to be compiled
set(SOURCE_FILES
        src/core/core_func.cpp
        src/core/chars_identify.cpp
        src/core/chars_recognise.cpp
        src/core/chars_segment.cpp
        src/core/feature.cpp
        src/core/plate_detect.cpp
        src/core/plate_judge.cpp
        src/core/plate_locate.cpp
        src/core/plate_recognize.cpp
        src/core/params.cpp

        src/train/ann_train.cpp
        src/train/annCh_train.cpp
        src/train/svm_train.cpp
        src/train/train.cpp
        src/train/create_data.cpp

        src/util/util.cpp
        src/util/program_options.cpp
        src/util/kv.cpp
        )


# pack objects to static library
add_library(easypr STATIC ${SOURCE_FILES})

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  set(EXECUTABLE_NAME "demo_darwin_amd64")
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(EXECUTABLE_NAME "demo_arm")
endif ()

# test cases
add_executable(${EXECUTABLE_NAME} test/main.cpp)

# link opencv libs,指定在链接目标文件的时候需要链接到外部库，其效果类似gcc的编译参数“-l”，可以解决外部库的依赖问题。
target_link_libraries(${EXECUTABLE_NAME} easypr thirdparty_arm -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -ldl -lm -lpthread -lrt)

# MESSAGE(${CMAKE_BINARY_DIR}/../) 
SET_TARGET_PROPERTIES(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/../")