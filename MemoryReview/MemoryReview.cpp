
#include <iostream>
using namespace std;

int Square(int& i)
{
	i = i * i;
	return i;
}

int Double(int* i)
{
	*i = *i * 2;
	return *i;
}

struct Person
{
	char name[32];
	int id;
};

int main()
{
	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	// 
	int i = 5;
	// 
	// declare a int reference and set it to the int variable above
	// 
	int& reference = i;
	// 
	// output the int variable
	// 
	cout << "Int variable: " << reference << endl;
	// 
	// set the int reference to some number
	// 
	reference = 2;
	// 
	// output the int variable
	// 
	cout << "Int variable: " << reference << endl;
	// 
	// what happened to the int variable when the reference was changed? (insert answer)
	// 
	cout << "The int variable was changed to " << i << " after I swapped it." << endl;
	// 
	// output the address of the int variable
	// 
	cout << "Address of int variable: " << &i << endl;
	// 
	// output the address of the int reference
	// 
	cout << "Address of int reference: " << &reference << endl;
	// 
	// are the addresses the same or different? (insert answer)
	// 
	cout << "The addresses are the same." << endl;
	// 
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter (i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	// 
	reference = Square(reference);
	// 
	// output the int variable to the console
	// 
	cout << "Int variable: " << reference << endl;
	// 
	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	// ** POINTER VARIABLE **
	//
	// declare an int pointer, set it to nullptr (it points to nothing)
	// 
	int* pointer = nullptr;
	// 
	// set the int pointer to the address of the int variable created in the REFERENCE section
	// 
	pointer = &i;
	// 
	// output the value of the pointer
	// 
	cout << "Pointer: " << pointer << endl;
	// 
	// what is this address that the pointer is pointing to? (insert answer)
	// 
	cout << "The address is the address of the int variable." << endl;
	// 
	// output the value of the object the pointer is pointing to (dereference the pointer)
	// 
	cout << "The value of the object the pointer is pointing to is: " << *pointer << endl;
	// 
	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	// 
	*pointer = Double(pointer);
	// 
	// output the dereference pointer
	// 
	cout << "Pointer: " << *pointer << endl;
	// 
	// output the int variable created in the REFERENCE section
	// 
	cout << "Int variable: " << i << endl;
	// 
	// did the int variable's value change when using the pointer?

	cout << "Yes, the int variable's value changed to " << i << endl;
}