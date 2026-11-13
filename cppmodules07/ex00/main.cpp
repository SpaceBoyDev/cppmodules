#include "include/whatever.hpp"

#include <iostream>

int	main(void)
{
	int a = 10;
	int b = 10;

	float c = 0.f;
	float d = 100.5f;

	std::cout << "Variable a\nValue: " << a
		<< "\nAddress: " << &a << "\n\n";
	std::cout << "Variable b\nValue: " << b
		<< "\nAddress: " << &b << "\n\n";
	std::cout << "\nMax: " << max(a, b) << "\nAddress: " << &max(a, b);
	std::cout << "\n\nMin: " << min(a, b) << "\nAddress: " << &min(a, b);


	std::cout << "\n\nVariable c\nValue: " << c
		<< "\nAddress: " << &c << "\n\n";
	std::cout << "Variable d\nValue: " << d
		<< "\nAddress: " << &d << "\n\n";
	std::cout << "\nMax " << max(c, d) << "\nAddress: " << &max(c, d);
	std::cout << "\n\nMin " << min(c, d) << "\nAddress: " << &min(c, d);


	bool isTrue = true;
	bool isFalse = false;

	std::cout << "\n\nVariable isTrue\nValue: " << isTrue
		<< "\nAddress: " << &isTrue << "\n\n";
	std::cout << "Variable isFalse\nValue: " << isFalse
		<< "\nAddress: " << &isFalse << "\n\n";
	swap<bool>(isTrue, isFalse);
	std::cout << "Variables swapped\n"; 

	std::cout << "\nVariable isTrue\nValue: " << isTrue
		<< "\nAddress: " << &isTrue << "\n\n";
	std::cout << "Variable isFalse\nValue: " << isFalse
		<< "\nAddress: " << &isFalse << "\n\n";


	std::cout << "EXAMPLE\n";
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	}
	return (0);
}