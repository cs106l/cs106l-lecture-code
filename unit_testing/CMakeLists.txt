cmake_minimum_required(VERSION 3.12)
project(google_test_example_project)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/1b96fa13f549387b7549cc89e1a785cf143a1a50.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing() #to discover tests in test explorer 

file(GLOB SRC_FILES "*.cpp")
add_executable(main ${SRC_FILES}) # add this executable

target_link_libraries(main PRIVATE GTest::gtest_main) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(main) # discovers tests by asking the compiled test executable to enumerate its tests
