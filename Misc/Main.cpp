#include "Point.h"
#include <iostream>
#include <vector>

using namespace std;

// namespace keyword creates a new scope where you must use the namespace prefix (useful for large projects, or clashing names)
// Can also be included with the using keyword
namespace math {
	// Template with multiple typenames so you're able to use different types
	template <typename T1, typename T2>
	T1 max(T1 a, T2 b) {
		// Shorthand if statement that returns a or b depending on which is greater
		return (a > b) ? a : b;
	};
}

// Ampersand after the type means that the list in memory is being passed through, rather than making a copy (Good for efficiency)
// const keyword means the passed variable cannot be modified
void printVector(const vector<string>& names) {
	for (string name : names) {
		cout << name << endl;
	}
}

int main(){

	string br = "----------------------------------------";

	// Calling max function from standard namespace and self-created namespace
	cout << std::max<int>(5, 10) << endl;
	cout << math::max<int, float>(5, 10.0f) << endl;

	cout << br << endl;

	vector<string> names = { "John", "Doe", "Jane" };
	printVector(names);

	cout << br << endl;

	// Writing math2:: since "Point.h" is in the math2 namespace
	math2::ipoint p1(23, 24);
	math2::ipoint p2(16, 29);
	math2::ipoint p3;
	// Add sign performs the method with operator + (defined in Point.h)
	p3 = p1 + p2;
	cout << "(" << p1.getX() << ", " << p1.getY() << ")" << endl;
	cout << p3 << endl;
}
