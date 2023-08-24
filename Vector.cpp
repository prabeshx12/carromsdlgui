#include "headers/Vector.h"
#include <cmath>

template<typename T>
Vector<T>::Vector() : x(0), y(0)
{
    calculateUnitVector();
}

template<typename T>
Vector<T>::Vector(T a, T b) : x(a), y(b)
{
    calculateUnitVector();
}

// Calculate the magnitude of the vector
template<typename T>
T Vector<T>::magnitude() const
{
    return sqrt(x * x + y * y);
}

// Normalize the vector
template<typename T>
Vector<T> Vector<T>::normalized() const
{
    T mag = magnitude();
    if (mag != 0)
        return Vector<T>(x / mag, y / mag);
    else
        return *this; // Return as is (avoid division by zero)
}
