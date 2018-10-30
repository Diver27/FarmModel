cmake_minimum_required(VERSION 3.10)
project(FarmModel)

set(CMAKE_CXX_STANDARD 11)

add_executable(testA test_A.cpp ../main/plants/AbstractPlant.h ../main/plants/Wheat.h ../main/plants/Cotton.h ../main/plants/PlantActionStrategy.h ../main/plants/PlantsField.h ../main/iteartor/Iterator.h ../main/visitor/Visitor.h ../main/visitor/ConcreteVisitor.h)
add_executable(testB test_B.cpp ../main/product)
add_executable(testBuilding testBuilding.cpp ../main/building/building.h)