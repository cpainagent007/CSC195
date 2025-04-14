
#include "Human.h"
#pragma once
#include <iostream>

using namespace std;

//Colon symbol indicates inheritance from Human class, and requires public keyword
//Can inherit from more than one class, but not recommended
class Student : public Human {
public:
	Student() {
		cout << "Student default constructor called" << endl;
	}
	//Constructor with member initializer list from parent constructor
	Student(string name, age_t age, float gpa) :
		Human{ name, age }, m_gpa(gpa) {
		cout << "Student paramater constructor called" << endl;
	}

	float getGPA() {
		return m_gpa;
	}
	void setGPA(float gpa) {
		m_gpa = gpa;
	}

private:
	float m_gpa = 0.0f;
};