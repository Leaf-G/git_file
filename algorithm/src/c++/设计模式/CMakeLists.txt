#最低要求
cmake_minimum_required(VERSION 3.21)
#项目名称
project(Demo)

#设置CMake变量
set(CMAKE_CXX_STANDARD 17)

#将main.cpp生成可执行程序Demo

#add_executable(SingleInstance SingleInstance.cpp)
add_executable(EagerSingleton EagerSingleton.cpp)
add_executable(LazySingleton LazySingleton.cpp)
add_executable(Factory Factory.cpp)
add_executable(simpleFactory simpleFactory.cpp)
add_executable(Observer Observer.cpp)
