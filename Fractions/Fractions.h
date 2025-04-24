#pragma once
#include <iostream>

using namespace std;

namespace mathLib {
	template<typename T>
	class Fraction {
	public:
		Fraction() {};

		Fraction(T numerator, T denominator) : m_numerator(numerator), m_denominator(denominator) {
			if (denominator == 0) {
				m_denominator = 1;
			}
		}

		Fraction operator + (const Fraction& other) const {
			T new_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
			T new_denominator = m_denominator * other.m_denominator;
			return Fraction(new_numerator, new_denominator);
		}

		Fraction operator - (const Fraction& other) const {
			T new_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
			T new_denominator = m_denominator * other.m_denominator;
			return Fraction(new_numerator, new_denominator);
		}

		Fraction operator * (const Fraction& other) const {
			T new_numerator = m_numerator * other.m_numerator;
			T new_denominator = m_denominator * other.m_denominator;
			return Fraction(new_numerator, new_denominator);
		}

		Fraction operator / (const Fraction& other) const {
			if (other.m_numerator == 0) {
				T new_denominator = m_denominator * other.m_numerator;
				return Fraction(0, new_denominator);
			}
			T new_numerator = m_numerator * other.m_denominator;
			T new_denominator = m_denominator * other.m_numerator;
			return Fraction(new_numerator, new_denominator);
		}

		bool operator == (const Fraction& other) const {
			return (m_numerator * other.m_denominator == other.m_numerator * m_denominator);
		}

		bool operator != (const Fraction& other) const {
			return !(*this == other);
		}

		bool operator < (const Fraction& other) const {
			return (m_numerator * other.m_denominator < other.m_numerator * m_denominator);
		}

		bool operator > (const Fraction& other) const {
			return (m_numerator * other.m_denominator > other.m_numerator * m_denominator);
		}

		bool operator <= (const Fraction& other) const {
			return (m_numerator * other.m_denominator <= other.m_numerator * m_denominator);
		}

		bool operator >= (const Fraction& other) const {
			return (m_numerator * other.m_denominator >= other.m_numerator * m_denominator);
		}

		friend std::ostream& operator << (std::ostream& os, const Fraction& fraction) {
			os << fraction.m_numerator << "/" << fraction.m_denominator;
			return os;
		}

		friend std::istream& operator >> (std::istream& is, Fraction& fraction) {
			char slash;
			is >> fraction.m_numerator >> slash >> fraction.m_denominator;
			if (fraction.m_denominator == 0) {
				fraction.m_denominator = 1;
			}
			return is;
		}

		T findGCD(T a, T b) const {
			while (b != 0) {
				T t = b;
				b = a % b;
				a = t;
			}
			return a;
		}

		Fraction<T> simplify() const {
			T gcd = findGCD(abs(m_numerator), abs(m_denominator));
			T simplifiedNumerator = m_numerator / gcd;
			T simplifiedDenominator = m_denominator / gcd;
			if (simplifiedDenominator < 0) {
				simplifiedNumerator = -simplifiedNumerator;
				simplifiedDenominator = -simplifiedDenominator;
			}
			return Fraction(simplifiedNumerator, simplifiedDenominator);
		}

		float toFloat() const {
			return static_cast<float>(m_numerator) / m_denominator;
		}
	private:
		T m_numerator;
		T m_denominator;
	};
};