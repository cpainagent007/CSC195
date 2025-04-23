#include "Point.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// define keyword is used to create a constant variable, must be assigned a unique name
// Everywhere where NAME exists, it will be replaced with "Tester" (good for large projects)
#define NAME "Tester"
#define PI 3.14159265358979323f
// Creating a debug definition that can be used to enable or disable a debug mode
#define DEBUG

// Defining a platform to be used in the program
// ONLY ONE should be defined at a time (manual change)
#define XBOX
#define PLAYSTATION
#define NINTENDO

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

// Creating a manual write function, passing in a reference to the cout object
template<typename T>
void streamOut(ostream& ostr, const T& value) {
	ostr << value << endl;
}

// Same, but for reading
template<typename T>
void streamIn(istream& istr, T& text) {
	// getline function reads a line of text from the input stream
	getline(istr, text);
}

int main(){

	// Can use defined DEBUG to enable or disable debug mode
	// Built-int _DEBUG can be toggled on or off next to x64 button at the top of the screen
#ifdef _DEBUG
	cout << "Debug mode is on" << endl;
#endif

	// Pairing #define with #ifdef allows you to check if a certain platform is being used
	// Extremely helpful for cross-platform development
	// Can create more like _DEBUG in the Configuration Manager, accessible from the drop down
	// Makes it easier to test platforms and eliminate manual code changes in the #define area
#ifdef XBOX
	cout << "XBOX" << endl;
#endif

	string br = "----------------------------------------";



	// cerr streamer object is used to write to the standard error stream (Helps troubleshooting if you have a crashing program)
	streamOut(cerr, "Hello World");

	// ofstream is a class that allows you to write to files
	ofstream fstream("test.txt");
	streamOut(fstream, "Hello World");
	streamOut(fstream, "Spaghetti");
	// ofstream needs to be closed to save the file
	fstream.close();

	string text;
	streamIn(cin, text);
	cout << text << endl;

	// ifstream is a class that allows you to read from files
	ifstream ifstream("test2.txt");
	if (ifstream.is_open()) {
		streamIn(ifstream, text);
		cout << text << endl;
	}
	ifstream.close();

	math2::Point<int> p(4, 5);

	cin >> p;

	streamOut(fstream, p);

	if (ifstream.is_open()) {
		while (getline(ifstream, text)) {
			cout << text << endl;
		}
	}

	cout << br << endl;

	// Calling max function from standard namespace and self-created namespace
	cout << std::max<int>(5, 10) << endl;
	cout << math::max<int, float>(5, 10.0f) << endl;

	cout << br << endl;

	vector<string> names = { "John", "Doe", "Jane" };
	printVector(names);

	cout << br << endl;

	// Writing math2:: since "Point.h" is in the math2 namespace
	math2::Point<int> p1(23, 24);
	math2::Point<int> p2(16, 29);
	math2::Point<int> p3;
	// Add sign performs the method with operator + (defined in Point.h)
	p3 = p1 + p2;
	cout << "(" << p1.getX() << ", " << p1.getY() << ")" << endl;
	cout << p3 << endl;

	cout << br << endl;

	cout << "Name: " << NAME << endl;
	cout << "PI: " << PI << endl;
}