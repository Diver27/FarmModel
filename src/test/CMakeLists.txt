cmake_minimum_required(VERSION 3.10)
project(FarmModel)

set(CMAKE_CXX_STANDARD 11)

add_executable(testA test_A.cpp ../main/testClassA.h ../main/testClassB.h)
add_executable(testB test_B.cpp ../main/testClassA.h ../main/testClassB.h)