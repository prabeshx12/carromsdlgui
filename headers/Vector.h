#pragma once
template <typename T>

class Vector {

    private:
        // Calculate unit vector components
        void calculateUnitVector() {

            T mag = magnitude();
            if (mag != 0) {
                i = x / mag;
                j = y / mag;
            }
            else {
                i = 0;
                j = 0;
            }

        }

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
        Vector<T> operator+(const Vector<T>& other) const;

        // Overload the subtraction operator for vector subtraction
        Vector<T> operator-(const Vector<T>& other) const;

};
