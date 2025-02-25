cmake_minimum_required(VERSION 3.10)

project(cs106l_classes)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES "*.cpp")

add_executable(main ${SRC_FILES})
