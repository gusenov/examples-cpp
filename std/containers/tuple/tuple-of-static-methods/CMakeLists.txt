cmake_minimum_required(VERSION 3.14)
project(TupleOfMethods)

set(CMAKE_CXX_STANDARD 17)

add_executable(TupleOfMethods main.cc SomethingConcrete.cc Factory.cc)
