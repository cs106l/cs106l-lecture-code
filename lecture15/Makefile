# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20

# Source files and target
SRCS = $(wildcard src/*.cpp)
TARGET = main

# Default target
all:
	$(CXX) $(CXXFLAGS) $(SRCS) -Iinclude -o $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)
