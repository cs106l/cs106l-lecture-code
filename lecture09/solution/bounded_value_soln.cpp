/* File: bounded_value_soln.cpp
 * Author: Preston Seay
 *
 * This file implements the BoundedValue template class.
 */

template <typename T>
BoundedValue<T>::BoundedValue(T value, T minValue, T maxValue) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    if (value < minValue) {
        this->value = minValue;
    } else if (value > maxValue) {
        this->value = maxValue;
    } else {
        this->value = value;
    }
}

template <typename T>
T BoundedValue<T>::get() const {
    return value;
}

template <typename T>
void BoundedValue<T>::set(T newValue) {
    value = newValue;
    if (value < minValue) {
        this->value = minValue;
    } else if (value > maxValue) {
        this->value = maxValue;
    }
}

template <typename T>
T BoundedValue<T>::getMin() const {
    return minValue;
}

template <typename T>
T BoundedValue<T>::getMax() const {
    return maxValue;
}

template <typename T>
void BoundedValue<T>::adjust(T delta) {
    set(value + delta);
}