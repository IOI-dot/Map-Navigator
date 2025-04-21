cmake_minimum_required(VERSION 3.31)
project(MapNavigator)

set(CMAKE_CXX_STANDARD 20)

add_header(MapNavigator
        Dynamic_Array.h
        Graph.h
)

add_executable(MapNavigator
        Graph.cpp
        main.cpp
)

