
#include <iostream>
#include <memory>

using namespace std;

// Default access level for structs is public (unlike classes, which are private by default)
struct smartPointer{
	// Delete keyword is used to delete the default constructor. This prevents the user from creating a smart pointer with a default constructor
	// Same effect as creating a constructor with parameters, or making a default constructor private
	// This is a good way to show that the default constructor should not be used in the code
	smartPointer() = delete;
	// Using colon and parenthesis to initialize rather than putting data in the parenthesis
	smartPointer(int* ptr) : m_ptr(ptr) {}
	// Destructor. This is called when the object goes out of scope
	~smartPointer() {
		delete m_ptr;
		cout << "smartPointer destructor called" << endl;
	}

	int* m_ptr = nullptr;
};

// Template struct. This allows us to create a smart pointer for any type of object, not just integers
template<typename T>
struct templateSmartPointer {
	
	templateSmartPointer() = default;
	
	templateSmartPointer(T* ptr) : m_ptr(ptr) {}
	
	~templateSmartPointer() {
		delete m_ptr;
		cout << "templateSmartPointer destructor called" << endl;
	}

	T dereference() {
		return *m_ptr;
	}

	// Creating operator overloads. This allows us to create methods to do common operations (quality of life/shorthand code)
	T operator * () {
		return *m_ptr;
	}

	T* operator & () {
		return m_ptr;
	}

	T operator + () {
		return (*m_ptr + *m_ptr);
	}

	T* m_ptr = nullptr;
};

// Global variable. Everything after this is seen, everything before this is not seen (C++ reads top down)
int global = 10;

int main(){

	string br = "----------------------------------------";

	// Possible, since global is visible
	global = 20;

    int i = 5;
    int* ipntr = &i;

	// Scope operator. Everything outside of the scope operator is not seen, everything inside (including more scope operations) can be seen
	{
		// Creating a new smart pointer object that points to an int
		smartPointer sptr{ new int(10) };
		// Printing out the value of the smart pointer without the need for a getter/setter since it is in a struct
		cout << *sptr.m_ptr << endl;

		// Template smart pointer can use any type of object, not just int
		templateSmartPointer<int> tptr{ new int(20) };
		templateSmartPointer<double> tptr2{ new double(30.5) };
		templateSmartPointer<char> tptr3{ new char('A') };
		templateSmartPointer<string> tptr4{ new string("Hello") };
		// Printing out the value of the template smart pointer, dereferencing with an asterisk
		cout << *tptr.m_ptr << endl;
		// Printing out the value of the template smart pointer, dereferencing with a method
		cout << tptr2.dereference() << endl;
		// Printing out the value of the template smart pointer, dereferencing with an operator overload method
		cout << *tptr3 << endl;
		// Printing out the address of the template smart pointer using an operator overload method
		cout << &tptr4 << endl;
		// Printing out the value after using the operator overload method +
		cout << +tptr << endl;
	}
	// smartPointer object is automatically deleted through the destructor when it goes out of scope. Eliminates the need for a delete statement
	// Objects are destructed in the reverse order they are created (stack order, LIFO)

	cout << br << endl;

	// Unique and Shared pointers replace raw pointers in modern C++ code
	{
		// Unique pointer
		// Can only point to one object at a time
		unique_ptr<int> uptr = make_unique<int>(10);
		cout << *uptr << endl;

		cout << br << endl;

		// Shared pointer
		// Can chare the pointed object with others pointers
		shared_ptr<int> shptr = make_shared<int>(20);
		cout << shptr.use_count() << endl;
		shared_ptr<int> shptr2 = shptr;
		shared_ptr<int> shptr3 = shptr;
		shared_ptr<int> shptr4 = shptr;
		cout << shptr.use_count() << endl;
	}
	
}

