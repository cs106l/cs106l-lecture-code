/* File: bounded_value.cpp
 * Author: Preston Seay
 *
 * This file implements the BoundedValue template class.
 * 
 * Somtimes, this implementation of the template would
 * be called a .tpp file, since it's somewhat special
 * as it's included at the bottom of the .h.
 */

// TODO: Constructor
template <typename T>
BoundedValue<T>::BoundedValue(T value, T minValue, T maxValue);

// TODO: Return stored value
template <typename T>
T BoundedValue<T>::get() const;

// TODO: Set value and enforce bounds
template <typename T>
void BoundedValue<T>::set(T newValue);

// TODO: Return minimum bound
template <typename T>
T BoundedValue<T>::getMin() const;

// TODO: Return maximum bound
template <typename T>
T BoundedValue<T>::getMax() const;

// OPTIONAL TODO:
template <typename T>
void BoundedValue<T>::adjust(T delta);