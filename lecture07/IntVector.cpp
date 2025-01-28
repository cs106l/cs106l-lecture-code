#include "IntVector.h"
#include <stdexcept>

IntVector::IntVector()
{
  _size = 0;
  _capacity = 4;
  _data = new int[_capacity];
}

IntVector::~IntVector()
{
  delete[] _data;
}

void IntVector::resize()
{
  auto newData = new int[_capacity * 2];
  for (size_t i = 0; i < _size; i++)
  {
    newData[i] = _data[i];
  }

  delete[] _data;
  _capacity *= 2;
  _data = newData;
}

void IntVector::push_back(const int& value)
{
  if (_size == _capacity) {
    resize();
  }

  _data[_size] = value;
  _size++;
}

int& IntVector::at(size_t index)
{
  if (index >= _size)
  {
    throw std::out_of_range("Out of range!");
  }

  return _data[index];
}

int& IntVector::operator[](size_t index)
{
  return _data[index];
}

size_t IntVector::size()
{
  return _size;
}

bool IntVector::empty()
{
  return _size == 0;
}

IntVector::iterator IntVector::begin()
{
  return _data;
}

IntVector::iterator IntVector::end()
{
  return _data + _size;
}