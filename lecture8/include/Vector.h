#pragma once

#include <cstddef>

template <typename T>
class Vector {
public:
  using iterator = T*;

  Vector();
  ~Vector();

  void push_back(const T& value);

  T& at(size_t index);
  T& operator[](size_t index);

  size_t size();
  bool empty();

  iterator begin();
  iterator end();
private:
  size_t _size;
  size_t _capacity;
  T* _data;

  void resize();
};

#include "../include/Vector.cpp"