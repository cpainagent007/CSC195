
#include "Human.h"

//Static member variables must be defined outside the class
int Human::m_count = 0;
const float Human::m_tax = 0.0825f;

void func() {
	cout << "This is a function" << endl;
}

void Human::setAge(unsigned short age) {
	m_age = age;
}