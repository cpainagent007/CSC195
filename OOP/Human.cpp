
#include "Human.h"
#include "Console.h"

//Static member variables must be defined outside the class
int Human::m_count = 0;
const float Human::m_tax = 0.0825f;

void func() {
	cout << "This is a function" << endl;
}

void Human::setAge(unsigned short age) {
	m_age = age;
}

void Human::Read(){
	cout << "Enter name: ";
	cin >> m_name;
	cout << "Enter age: ";
	m_age = getData<age_t>();
}

void Human::Write() {
	cout << "Name: " << m_name << endl;
	cout << "Age: " << m_age << endl;
}