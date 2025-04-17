
#include "School.h"
#include "Student.h"
#include "Teacher.h"
#include "Worker.h"
#include <iostream>

using namespace std;

//for each loop to delete all humans once the destructor is called
School::~School() {
	cout << "School destructor called" << endl;
	for (Human* human : m_humans) {
		delete human;
	}
	//Clearing the vector to free up memory
	m_humans.clear();
}

void School::add(Human::Type type) {

	//Creating a null pointer to the base class (Human) to later assign then add to the vector
	Human* human = nullptr;

	//Using switch statement to determine which type of Human to create
	switch (type) {
	case Human::STUDENT:
		human = new Student;
		break;
	case Human::WORKER:
		human = new Worker;
		break;
	case Human::TEACHER:
		human = new Teacher;
		break;
	default:
		break;
	}

	human->Read();

	//Adding assigned pointer to the vector, since it is now one of the child classes
	m_humans.push_back(human);

	//Not deleting the pointer here, since it is now owned by the vector
	//Pointer will be deleted later in the destructor
}
void School::displayAll() {
	for (Human* human : m_humans) {
		human->Write();
	}
}
void School::displayByType(Human::Type type) {
	for (Human* human : m_humans) {
		if (human->getType() == type) {
			human->Write();
		}
	}
}
void School::displayByName(string name) {
	for (Human* human : m_humans) {
		if (human->getName() == name) {
			human->Write();
		}
	}
}