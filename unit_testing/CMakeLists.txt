cmake_minimum_required(VERSION 3.12)
set(GOOGLETEST_VERSION 1.15.2)

project(google_test_example_project)

enable_testing() #to discover tests in test explorer 

add_subdirectory(googletest/googletest) # add googletest subdirectory

include_directories(googletest/googletest/include) # this is so we can #include <gtest/gtest.h>

file(GLOB SRC_FILES "*.cpp")
add_executable(main ${SRC_FILES}) # add this executable

target_link_libraries(main PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(main) # discovers tests by asking the compiled test executable to enumerate its tests
