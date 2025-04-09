
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
}