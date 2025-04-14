
//Student has #include "Human.h", so access to Human.h is already included when using #include "Student.h"
#include "Student.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Number of people: " << Human::getCount() << endl;
	{
		Human human1;
		//Parent class initializes first, then child class
		Student student1;
		//Using braces to indicate using a constructor instead of a method
		Student student2{ "John Doe", 20, 3.5f };
		cout << "Number of people: " << Human::getCount() << endl;
		//student1 does not have a name or age, so it will print an empty string and 0
		cout << student1.getName() << endl;
		cout << student1.getAge() << endl;
		cout << student2.getName() << endl;
		cout << student2.getAge() << endl;
		//Destructor will be called automatically when the object goes out of scope
	}
	cout << "Number of people: " << Human::getCount() << endl;
}
