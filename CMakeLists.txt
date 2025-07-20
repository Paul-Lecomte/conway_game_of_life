cmake_minimum_required(VERSION 3.26)
project(GameOfLife LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GameOfLife main.cpp)