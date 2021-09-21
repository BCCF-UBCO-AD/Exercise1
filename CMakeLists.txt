cmake_minimum_required(VERSION 3.21)
project(ex1)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(include/third-party)
file(GLOB SOURCES src/*.cpp)
file(GLOB THIRDPARTY src/third-party/*.cpp)
add_executable(ex1 ${SOURCES} ${THIRDPARTY})
