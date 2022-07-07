cmake_minimum_required(VERSION 3.19)
project(UnnamedNamespaceWithinNamedNamespace)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cc A.cc B.cc)