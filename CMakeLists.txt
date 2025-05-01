cmake_minimum_required(VERSION 3.31)
project(MapNavigator)

set(CMAKE_CXX_STANDARD 20)
add_executable(MapNavigator
        Graph.cpp
        main.cpp
        Dijkstra.cpp
        File_Reader.cpp
)

