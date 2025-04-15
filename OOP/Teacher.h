
#include "Human.h"
#pragma once
#include <iostream>

using classroom_t = unsigned short;
using namespace std;

class Teacher : public Human {
public:
	Teacher() {
		cout << "Teacher default constructor called" << endl;
	}
	Teacher(string name, age_t age, string className, classroom_t classroom) :
		Human{ name, age }, m_className(className), m_classroom(classroom) {
		cout << "Teacher parameter constructor called" << endl;
	}

	string getClassName() {
		return m_className;
	}
	void setClassName(string className) {
		m_className = className;
	}
	classroom_t getClassroom() {
		return m_classroom;
	}
	void setClassroom(classroom_t classroom){
		if (classroom < 300 || classroom > 400) return;
		m_classroom = classroom;
	}
	Type getType() override{
		return TEACHER;
	}
	void work() override{
		cout << "Teacher Working" << endl;
	}

private:
	string m_className;
	classroom_t m_classroom = 0;
};
