#include "headers/Vector.h"

template <typename T>
Vector<T>::Vector() :x{ 0 }, y{ 0 } { calculateUnitVector(); }

template <typename T>
Vector<T>::Vector(T a, T b) : x{ a }, y{ b } { calculateUnitVector(); }

template <typename T>
T Vector<T>::magnitude() const {

    return(x * x + y * y);

}

template <typename T>
Vector<T> Vector<T>::normalized() const {

    T mag = magnitude();
    if (mag != 0)
        return Vector<T>(x / mag, y / mag);
    else
        return *this; // Return as is (avoid division by zero)

}

template <typename  T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {

    return Vector<T>(x + other.x, y + other.y);

}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T>& other) const {

    return Vector<T>(x - other.x, y - other.y);

}

template <typename T>
Vector<T> operator*(const Vector<T>& v, T scalar) {

    return Vector<T>(v.x * scalar, v.y * scalar);

}

template <typename T>
Vector<T> operator*(T scalar, const Vector<T>& v) {

    return v * scalar;

}