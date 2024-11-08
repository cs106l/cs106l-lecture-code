cmake_minimum_required(VERSION 3.10)

project(cs106l_movesemantics)

set(CMAKE_CXX_STANDARD 20)

if(ENABLE_MOVE_SEMANTICS)
    add_definitions(-DENABLE_MOVE_SEMANTICS)
endif()

add_executable(main main.cpp)