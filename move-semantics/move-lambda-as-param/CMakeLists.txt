cmake_minimum_required(VERSION 3.14)
project(MoveLambda)

set(CMAKE_CXX_STANDARD 17)

# https://unix.stackexchange.com/a/188167/443904
# https://stackoverflow.com/a/35154301/12847278
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g2")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -g2")

add_executable(${PROJECT_NAME}
    main.cc
    test1.h
    test2.h
    test3.h
    test4.h
    test5.h
    test6.h
    test7.h
    test8.h
    test9.h
    test10.h
    test11.h
    test12.h
)
