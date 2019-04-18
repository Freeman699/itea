cmake_minimum_required(VERSION 3.14.2)

project(Structs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Werror -pedantic")

file (GLOB CPPS "*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})