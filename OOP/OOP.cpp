
//Student has #include "Human.h", so access to Human.h is already included when using #include "Student.h"
#include "Student.h"
#include "Teacher.h"
#include "School.h"
#include <iostream>
#include <vector>

using namespace std;

void old() {
	//Class full of old work/notes

	string br = "\n----------------------------------------\n\n";

	cout << sizeof(unsigned short) << endl;
	cout << sizeof(int) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(string) << endl;
	cout << sizeof(Human) << endl;
	cout << sizeof(Student) << endl;
	cout << sizeof(Teacher) << endl;


	cout << br;

	cout << "Number of people: " << Human::getCount() << endl;

	{
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

	cout << br;

	Student* student = new Student{ "S-Test", 20, 3.5f };
	Teacher* teacher = new Teacher{ "T-Test", 30, "Class", 101 };
	Human* student2 = new Student{ "S-Test2", 20, 3.0f };

	//Use either asterisk or arrow operator to access the member methods
	//Arrow operator is recommended/preferred
	cout << (*student).getName() << endl;
	cout << student->getAge() << endl;
	//Casting enum to int to print the value of the enum
	cout << static_cast<int>(student->getType()) << endl;

	dynamic_cast<Student*>(student2)->setGPA(3.5f);

	vector<Human*> school;

	school.push_back(student);
	school.push_back(teacher);
	school.push_back(student2);
	school.push_back(new Student{ "S-Test3", 20, 3.0 });
	school.push_back(new Teacher{ "T-Test2", 30, "Class", 100 });

	for (int i = 0; i < school.size(); i++) {
		cout << br;

		cout << "Name: " << school[i]->getName() << endl;
		cout << "Age: " << school[i]->getAge() << endl;
		school[i]->work();
		//Checking and casting to access class-specific methods
		if (school[i]->getType() == Human::STUDENT) {
			cout << "GPA: " << dynamic_cast<Student*>(school[i])->getGPA() << endl;
		}
		if (school[i]->getType() == Human::TEACHER) {
			cout << "Class Name: " << dynamic_cast<Teacher*>(school[i])->getClassName() << endl;
			cout << "Classroom: " << dynamic_cast<Teacher*>(school[i])->getClassroom() << endl;
		}
		//Another way to check the type of the object is to use dynamic_cast (recommended)
		if (dynamic_cast<Student*>(school[i])) {}
	}

	cout << br;

	delete student;
}

int main(){

	string br = "\n----------------------------------------\n\n";

	School school;

	bool quit = false;

	while (!quit) {
		//Display menu
		cout << "1. Add person" << endl;
		cout << "2. Display all" << endl;
		cout << "3. Display all of type" << endl;
		cout << "4. Quit" << endl;

		unsigned short selection;
		cin >> selection;

		switch (selection)
		{
		case 1:
			cout << "1. Add Student" << endl;
			cout << "2. Add Worker" << endl;
			cout << "3. Add Teacher" << endl;
			unsigned short type;
			cin >> type;
			//Subtracting 1 from type since enumeration starts at 0
			school.add(static_cast<Human::Type>(type-1));
			break;
		case 2:
			//system("cls"); clears console
			system("cls");
			school.displayAll();
			break;
		case 3:
			break;
		case 4:
		default:
			system("cls");
			quit = true;
			break;
		}
	}
}
