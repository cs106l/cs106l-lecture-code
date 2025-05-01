cmake_minimum_required(VERSION 3.10)

project(cs106l_classes)

set(CMAKE_CXX_STANDARD 20)

include_directories(include utils)

file(GLOB SRC_FILES "src/*.cpp")

add_executable(main ${SRC_FILES})
