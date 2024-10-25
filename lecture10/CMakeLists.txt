cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cs106l_soundex)

include_directories(include)

configure_file(names.txt names.txt COPYONLY)

add_executable(main main.cpp src/soundex.cpp src/soundex-ranges.cpp)