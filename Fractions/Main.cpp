#include "Fractions.h"
#include <iostream>

int main() {

	mathLib::Fraction<int> fraction1{ 18, 5 };
    std::cout << fraction1 << std::endl;

	mathLib::Fraction<int> fraction2{ 15, 6 };
    std::cout << fraction2 << std::endl;
    std::cout << "simplify: " << fraction2.simplify() << std::endl;

    std::cout << fraction1 << " == " << fraction2 << " result: " << (fraction1 == fraction2) << std::endl;
    std::cout << fraction1 << " > " << fraction2 << " result: " << (fraction1 > fraction2) << std::endl;

    std::cout << fraction1 << " + " << fraction2 << " result: " << (fraction1 + fraction2) << std::endl;
    std::cout << fraction1 << " * " << fraction2 << " result: " << (fraction1 * fraction2) << std::endl;

    mathLib::Fraction<int> fraction3;
    std::cout << "input fraction (numerator - denominator): \n";
    std::cin >> fraction3;
    std::cout << fraction3 << std::endl;
    std::cout << fraction3.toFloat() << std::endl;
};

