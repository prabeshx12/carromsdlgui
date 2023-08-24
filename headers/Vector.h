#pragma once

template <typename T>
class Vector
{
public:
    T x, y;
    T i, j;

    Vector();

    Vector(T a, T b);

    // Calculate the magnitude of the vector
    T magnitude() const;

    // Normalize the vector
    Vector<T> normalized() const;

    // Overload the addition operator for vector addition
    Vector<T> operator+(const Vector<T>& other) const
    {
        return Vector<T>(x + other.x, y + other.y);
    }

    // Overload the subtraction operator for vector subtraction
    Vector<T> operator-(const Vector<T>& other) const
    {
        return Vector<T>(x - other.x, y - other.y);
    }
    

private:
    // Calculate unit vector components
    void calculateUnitVector()
    {
        T mag = magnitude();
        if (mag != 0)
        {
            i = x / mag;
            j = y / mag;
        }
        else
        {
            i = 0;
            j = 0;
        }
    }
};
// Scalar multiplication of a vector
template <typename T>
Vector<T> operator*(const Vector<T>& v, T scalar)
{
    return Vector<T>(v.x * scalar, v.y * scalar);
}
// Scalar multiplication of a vector (reverse order)
template <typename T>
Vector<T> operator*(T scalar, const Vector<T>& v)
{
    return v * scalar;
}
template <typename T>
T operator*(const Vector<T>& u, const Vector<T>& v)
{
    return (u.x * v.x + u.y * v.y);
}
