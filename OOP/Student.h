
#pragma once
#include "Human.h"
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
	//Overriding the getType method from the parent class, also ensures you are specifically overriding an existing method (recommended)
	Type getType() override{
		return STUDENT;
	}
	void work() override{
		cout << "Student Working" << endl;
	}

	void Read() override;
	void Write() override;

private:
	float m_gpa = 0.0f;
};