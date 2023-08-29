#最低要求
cmake_minimum_required(VERSION 3.21)
#项目名称
project(backtrack)

#设置CMake变量
set(CMAKE_CXX_STANDARD 17)

#将main.cpp生成可执行程序Demo

add_executable(main main.cpp)
#add_executable(Difference Difference.cpp)
#add_executable(reverseString reverseString.cpp)
#add_executable(longestPalindrome longestPalindrome.cpp)