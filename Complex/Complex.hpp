#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

#include <iostream>
#include <cmath>
#include <cassert>

namespace Fish
{
    const static float pi = 3.141592653589793;

    inline float degree(float rad) { return 180.0 * rad / pi; }
    inline float radian(float deg) { return pi * deg / 180.0; }

	class Complex
	{
	public:
		float re, im;

		Complex(const float real, const float imaginary);
		Complex(const Complex& c);

		float Magnitude() const;
		float ArgumentRad() const;
		float ArgumentDeg() const;
		Complex Conjugate() const;

		Complex Add(const Complex& other) const;
		Complex Subtract(const Complex& other) const;
		Complex Multiply(const Complex& other) const;
		Complex DivideBy(const Complex& other) const;

		Complex operator+(const Complex& other) const;
		friend Complex operator+(const Complex& left, const float real);
		friend Complex operator+(const float real, const Complex& right);
		Complex operator-(const Complex& other) const;
		friend Complex operator-(const Complex& left, const float real);
		friend Complex operator-(const float real, const Complex& right);
		Complex operator*(const Complex& other) const;
		friend Complex operator*(const Complex& left, const float real);
		friend Complex operator*(const float real, const Complex& right);
		Complex operator/(const Complex& other) const;
		friend Complex operator/(const Complex& left, const float real);
		friend Complex operator/(const float real, const Complex& right);

		friend std::ostream& operator<<(std::ostream& stream, const Complex& c);
	};
}

#endif // COMPLEX_HPP_INCLUDED