cmake_minimum_required(VERSION 3.10)

project(cs106l_inheritance)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

if(VIRTUAL_INHERITANCE)
    add_definitions(-DVIRTUAL_INHERITANCE)
endif()

add_executable(main main.cpp src/SectionLeader.cpp src/Employee.cpp src/Person.cpp src/Student.cpp)