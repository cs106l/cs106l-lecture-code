#include <stdexcept>

template <typename T>
Vector<T>::Vector()
{
  _size = 0;
  _capacity = 4;
  _data = new T[_capacity];
}

template <typename T>
Vector<T>::~Vector()
{
  delete[] _data;
}

template <typename T>
void Vector<T>::resize()
{
  // Double the capacity of the vector

  auto newData = new T[_capacity * 2];
  for (size_t i = 0; i < _size; i++)
  {
    newData[i] = _data[i];
  }

  delete[] _data;
  _capacity *= 2;
  _data = newData;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
  if (_size == _capacity) {
    resize();
  }

  _data[_size] = value;
  _size++;
}

template <typename T>
T& Vector<T>::at(size_t index)
{
  if (index >= _size)
  {
    throw std::out_of_range("Out of range!");
  }

  return _data[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index)
{
  return _data[index];
}

template <typename T>
size_t Vector<T>::size()
{
  return _size;
}

template <typename T>
bool Vector<T>::empty()
{
  return _size == 0;
}

/* Changed from lecture:
 * Some compilers (e.g. g++) will require that when returning a
 * type that depends on a template type (for example, iterator in this example)
 * that you preface the return type with `typename`.
 * 
 * There are on-going proposals to get rid of this requirement from the language,
 * but alas, here we are.
 */
template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
  return _data;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
  return _data + _size;
}