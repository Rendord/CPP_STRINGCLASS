#pragma once
#include <iostream>
#include <string>


class Fraction {
private:
	int numerator;
	int denumerator;

public:

	Fraction();
	Fraction(const int, const int);
	std::string ToString() const;

	friend Fraction operator*(const Fraction&, const Fraction&);
};

Fraction operator*(const Fraction&, const Fraction&);
std::ostream& operator<<(std::ostream&, const Fraction& const);