cmake_minimum_required(VERSION 3.10)
project(FarmModel)

set(CMAKE_CXX_STANDARD 11)

add_executable(testPlant test_Plant.cpp ../main/plants/AbstractPlant.h ../main/plants/Wheat.h ../main/plants/Cotton.h ../main/plants/PlantActionStrategy.h ../main/plants/PlantsField.h ../main/iterator/Iterator.h ../main/visitor/Visitor.h ../main/visitor/ConcreteVisitor.h  ../main/product ../main/building/building.h ../main/animals/AbstractAnimal.h ../main/animals/Cow.h ../main/animals/Operation.h ../main/animals/Sheep.h ..  ../main/product/market.h ../main/product/productFactory.h ../main/product/trademark.h ../main/alarm/Alarm.h ../main/alarm/Alarm_MementoCommand.h)
add_executable(testBuilding testBuilding.cpp)
add_executable(testAnimal test_animal.cpp)
add_executable(testMaster test_MasterSingleton.cpp)
add_executable(testProduct testProduct.cpp)
add_executable(testAlarm test_Alarm.cpp)