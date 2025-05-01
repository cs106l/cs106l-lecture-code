/* This line makes sure that if another file #includes Vector.h
 * more than once, it will be as if it included it only once.
 *
 * Multiple includes can happen if, for example, we #include Vector.h
 * and also #include another file that itself #includes Vector.h
 * 
 * #pragma once is technically not part of the C++ language, but is a
 * compiler extension that virtually all compilers support
 */
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


/* Notice that the .h file for template #includes the .cpp file!
 * This is because, when instantiating templates, the compiler
 * must have full knowledge of both the declaration (this file)
 * and the definitions (.cpp file) of the template. 
 * 
 * Another way around this is to implement the template entirely
 * inside on file. Typically, these files are given the extension
 * .hpp, but this is arbitrary.
 * 
 * If you want to learn more about why this is, please check out
 * this C++ blog (also check out other pages in this, as it's a 
 * great reference for learning about C++):
 * 
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 */
#include "Vector.cpp"