#pragma once

#include <cstddef>

class IntVector {
public:
  using iterator = int*;

  IntVector();
  ~IntVector();

  void push_back(const int& value);

  int& at(size_t index);
  int& operator[](size_t index);

  size_t size();
  bool empty();

  iterator begin();
  iterator end();
private:
  size_t _size;
  size_t _capacity;
  int* _data;

  void resize();
};