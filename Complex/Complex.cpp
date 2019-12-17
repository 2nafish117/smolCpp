#include "Complex.hpp"

namespace Fish
{
	Complex::Complex(const float real = 0.0, const float imaginary = 0.0)
	: re(real), im(imaginary) { }

	Complex::Complex(const Complex& c)
	: re(c.re), im(c.im) { }

	float Complex::Magnitude() const
	{
		return sqrt(re*re + im*im);
	}

	float Complex::ArgumentRad() const
	{
        return atan2(re, im);
	}

	float Complex::ArgumentDeg() const
	{
		return degree(ArgumentRad());
	}

	Complex Complex::Conjugate() const
	{
		return Complex(re, -im);
	}

	Complex Complex::Add(const Complex& other) const
	{
		return Complex(re + other.re, im + other.im);
	}

	Complex Complex::Subtract(const Complex& other) const
	{
		return Complex(re - other.re, im - other.im);
	}

	Complex Complex::Multiply(const Complex& other) const
	{
		return Complex(other.re * re - other.im * im, im * other.re + re * other.im);
	}

	Complex Complex::DivideBy(const Complex& other) const
	{
		assert(other.re != 0 && other.im != 0 && "[DivideBy] divide by 0");
		return Complex((other.re * re + other.im * im) / (other.re*other.re+other.im*other.im),
						(im * other.re - re * other.im) / (other.re*other.re+other.im*other.im));
	}

	Complex Complex::operator+(const Complex& other) const
	{
		return Add(other);
	}

	Complex operator+(const Complex& left, const float real)
	{
		return Complex(real + left.re, left.im);
	}


	Complex operator+(const float real, const Complex& right)
	{
		return operator+(right, real);
	}

	Complex Complex::operator-(const Complex& other) const
	{
		return Subtract(other);
	}

	Complex operator-(const Complex& left, const float real)
	{
		return Complex(left.re - real, left.im);
	}

	Complex operator-(const float real, const Complex& right)
	{
		return Complex(real - right.re, -right.im);
	}

	Complex Complex::operator*(const Complex& other) const
	{
		return Multiply(other);
	}

	Complex operator*(const Complex& left, const float real)
	{
		return Complex(left.re * real, left.im * real);
	}

	Complex operator*(const float real, const Complex& right)
	{
		return Complex(right.re * real, right.im * real);
	}

	Complex Complex::operator/(const Complex& other) const
	{
		return DivideBy(other);
	}

	Complex operator/(const Complex& left, const float real)
	{
		Complex denominator(real, 0);
		return left.DivideBy(denominator);
	}

	Complex operator/(const float real, const Complex& right)
	{
		Complex numerator(real, 0);
		return(numerator.DivideBy(right));
	}

	std::ostream& operator<<(std::ostream& stream, const Complex& c)
	{
		if(c.im >= 0)
			stream << c.re << " + " << c.im << "i";
		else
			stream << c.re << " - " << -c.im << "i";
		return stream;
	}
}