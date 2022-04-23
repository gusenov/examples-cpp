cmake_minimum_required(VERSION 3.23)
project(RPG_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cc Object.cc)
