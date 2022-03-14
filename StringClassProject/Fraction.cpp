#include "Fraction.h"

int numerator; 
int denumerator;

Fraction::Fraction() {
	numerator = 0;
	denumerator = 1;
}

Fraction::Fraction(const int num, const int denum) {
	numerator = num;
	denumerator = denum;
}

std::string Fraction::ToString() const {
	return std::to_string(numerator) + " " + std::to_string(denumerator);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
	Fraction f(lhs.numerator * rhs.numerator, lhs.denumerator * rhs.denumerator);
		return f; 
}

std::ostream& operator<<(std::ostream& os, const Fraction& f) {
	os << f.ToString();
		return os;
}
