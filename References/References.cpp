
#include <iostream>

using namespace std;

void func1(int* p)
{
	if (p != nullptr) {
		*p = 10;
	}
	else {
		cout << "Pointer is null" << endl;
	}
}

//Using pointers to swap values (Does not modify the original variables, passed by value)
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Using references to swap values (Also modifies the original variables, passed by memory)
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	//Pointers are used to store the address of a variable, and can be null
	//References are used to create an alias for a variable, and cannot be null

	string breakPoint = "----------------------------";

	int i1 = 5;
	int i2 = 20;
	int* p1 = &i1;

	//Dereferencing a pointer
	p1 = nullptr;
	func1(p1);

	//Creating a reference to i1;
	int& r1 = i1;
	cout << r1 << endl;
	cout << i1 << endl;

	cout << &r1 << endl;

	//----------
	cout << breakPoint << endl;
	//----------

	//Swapping difference with pointers and references

	//Pointers (using & to get the address)
	cout << "i1: " << i1 << " i2: " << i2 << endl;
	swap(&i1, &i2);
	cout << "i1: " << i1 << " i2: " << i2 << endl;

	//----------
	cout << breakPoint << endl;
	//----------

	//References (no & to get the address, it happens in the function)
	cout << "i1: " << i1 << " i2: " << i2 << endl;
	swap(i1, i2);
	cout << "i1: " << i1 << " i2: " << i2 << endl;

	p1 = &i1;
	for (int i = 0; i < 1000; i++) {
		cout << *p1++ << endl;
	}
}
