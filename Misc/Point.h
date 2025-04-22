#pragma once
#include <iostream>

using namespace std;

namespace math2 {

	// using keyword to create a shorthand for the type
	using ipoint = Point<int>;
	using fpoint = Point<float>;

	template<typename T>
	class Point {
	public:
		Point() = default;
		Point(T x, T y) : m_x(x), m_y(y) {};

		// Adding a new point using the constructor inside of method
		// const keyword in parenthesis means that the function will not modify the variables
		// const keyword after parenthesis mean that the function will not modify the class
		// operator keyword means the method can be used as an operator (cuts down on code)
		Point<T> operator +(const Point<T>& otherPoint) const {
			return Point<T>(m_x + otherPoint.m_x, m_y + otherPoint.m_y);
		}

		Point<T> operator -(const Point<T>& otherPoint) const {
			return Point<T>(m_x - otherPoint.m_x, m_y - otherPoint.m_y);
		}

		bool operator ==(const Point<T>& otherPoint) const {
			return (m_x == otherPoint.m_x && m_y == otherPoint.m_y);
		}

		bool operator !=(const Point<T>& otherPoint) const {
			// *this is a deference to the current object
			return !(*this == other);
		}

		// Output operator overload that allows the sets to properly print
		// friend keyword allows the function to access private members of the class
		friend ostream& operator <<(ostream& ostream, const Point<T>& point) {
			ostream << "(" << point.m_x << ", " << point.m_y << ")";
			return ostream;
		}

		// Placing const keyword to relate that the function will not modify the class (good practice)
		T getX() const {
			return m_x;
		};
		T getY() const {
			return m_y;
		};
	private:
		T m_x = 0;
		T m_y = 0;
	};
};

