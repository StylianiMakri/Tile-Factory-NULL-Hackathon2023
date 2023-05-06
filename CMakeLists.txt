cmake_minimum_required(VERSION 3.25)
project(TileFactory)

set(CMAKE_CXX_STANDARD 23)

add_executable(TileFactory main.cpp CanvasAPI/canvas.h CanvasAPI/canvas.cpp CanvasAPI/canvas.cpp CanvasAPI/canvas.cpp TileAPI/shapes.h TileAPI/shapes.cpp stabilityAPI/stability.h stabilityAPI/stability.cpp)
