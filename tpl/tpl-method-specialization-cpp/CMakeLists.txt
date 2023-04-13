cmake_minimum_required(VERSION 3.25)
project(TPLMethodSpecializationCPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp StringUtils.cpp)
