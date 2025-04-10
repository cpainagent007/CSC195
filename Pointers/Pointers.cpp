
#include <iostream>

using namespace std;

void func1() {
	bool b = true;
	int i = 5;
}

void func2() {
	bool b = false;
	float f = 10;
	func1();
}

void func3() {
	int i[100000];
	//func3();
}

void setValue(int v) {
	v = 5;
}


//* after is used for declaration, * before is used for dereferencing/value stored at that address

void setValue2(int* v) {
	*v = 5;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

class Animal {
public:
	Animal(string name) {
		m_name = name;
	}

	string getName() {
		return m_name;
	}

private:
	string m_name;
};

int main() {
	string breakLine = "----------";

	int i = 5;
	float f = 4.5f;

	func1();
	//func2();
	//func3();


	// Items exist only in the brackets
	{
		//Creates a new integer on the heap
		int* pointer = new int(5);

		//Print address of p
		cout << pointer << endl;

		//Print value of p
		cout << *pointer << endl;

		//Delete the pointer once finished
		delete pointer;
	}

	//----------
	cout << breakLine << endl;
	//----------

	Animal* dog = new Animal("Dog");

	//Print name of dog instance
	cout << dog->getName() << endl;

	//Print name of dog object
	cout << (*dog).getName() << endl;

	//Delete the dog instance
	//Can't use dog after it has been deleted
	delete dog;
	dog = nullptr;

	//Check if dog is deleted (null check)
	if (dog) {
		cout << "Dog is not deleted" << endl;
	}
	else {
		cout << "Dog is deleted" << endl;
	}

	//----------
	cout << breakLine << endl;
	//----------

	//Creating an integer pointer on the heap with the size of int * 1000
	int* block = (int*) malloc(sizeof(int) * 1000);
	block[0] = 3;
	block[1] = 4;
	block[2] = 5;
	block[3] = 6;

	block++;
	cout << *(block + 2) << endl;

	//Free up space
	free(--block);

	int v1 = 10;
	int v2 = 20;

	//----------
	cout << breakLine << endl;
	//----------

	//Creating a pointer going to nothing
	int* p = nullptr;
	cout << p << endl;

	//Pointer now points to v1
	p = &v1;
	cout << p << endl;

	//Print out the point to v1 without using a pointer with &
	cout << &v1 << endl;

	//Setting the value of v1 indirectly through the pointer using *
	*p = 5;
	cout << *p << endl;

	//Setting the pointer to a different variable
	p = &v2;
	*p = 10;
	cout << *p << endl;

	//----------
	cout << breakLine << endl;
	//----------

	//Creates a temporary variable in the stack, doesn't actually change the value of v2
	setValue(v2);
	cout << *p << endl;
	cout << v2 << endl;

	//Sets the value of v2 to 5 through the address, so it stays in the heap
	setValue2(p);
	cout << *p << endl;
	cout << v2 << endl;

	//----------
	cout << breakLine << endl;
	//----------

	v1 = 20;
	cout << v1 << " " << v2 << endl;
	swap(&v1, &v2);
	cout << v1 << " " << v2 << endl;
	cout << *p << endl;
}