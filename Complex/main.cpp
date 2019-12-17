#include <iostream>

#include "Complex.hpp"

int main()
{
	Fish::Complex a(1, 1);
	Fish::Complex b(1, 1);
	std::cout << "mag = " << a.Magnitude() << std::endl;
	std::cout << "deg = " << a.ArgumentDeg() << std::endl;
	std::cout << "rad = " << a.ArgumentRad() << std::endl;
	std::cout << a << " " << b;

    return 0;
}