cmake_minimum_required(VERSION 3.10)
project(FarmModel)

set(CMAKE_CXX_STANDARD 11)

add_executable(testA test_A.cpp ../main/plants/AbstractPlant.h ../main/plants/Wheat.h ../main/plants/Cotton.h)