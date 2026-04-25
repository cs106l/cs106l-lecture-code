/* File: bounded_value.h
 * Author: Preston Seay
 *
 * This file defines the functionality of the bounded value template class.
 * 
 * Notice how this inlcudes the .cpp file at the bottom.
 */

template <typename T>
class BoundedValue {
private:
    T value;
    T minValue;
    T maxValue;

public:
    /* Initialize the value and its bounds,
       ensuring that the value is within its bounds. */
    BoundedValue(T value, T minValue, T maxValue);

    /* Get the stored value. */
    T get() const;

    /* Update the value, but keep it within bounds.
       If past the limits, set to the limit. */
    void set(T newValue);

    /* Returns the minimum bound. */
    T getMin() const;

    /* Returns the maximum bound. */
    T getMax() const;

    /* Bonus function: Add `delta` to the value,
       keeping it within bounds. */
    void adjust(T delta);
};

#include "bounded_value.cpp"