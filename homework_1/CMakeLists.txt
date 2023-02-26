cmake_minimum_required(VERSION 3.24)
project(numerical_hw)

set(CMAKE_CXX_STANDARD 11)

add_executable(numerical_hw main.cpp Summations.cpp Summations.h Statistics.cpp Statistics.h VectorLengthComputer.cpp VectorLengthComputer.h)
