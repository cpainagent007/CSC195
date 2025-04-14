
#pragma once
#include <iostream>

//_t suffix is used to indicate a type, allows the usage of age_t instead of unsigned short each time
//Data type is easily changeable, since the alias is used everywhere instead of the data type
using age_t = unsigned short;
//Alternative way to define a type alias
typedef unsigned short age_t;

using namespace std;

class Human {
public:
	/*
	//Constructor with parameters
	Human(string name, unsigned short age) {
		m_name = name;
		m_age = age;
		cout << "Constructor with parameters called" << endl;
	}
	//Constructor using this pointer to specify the object being constructed, not the parameter
	Human(string name, unsigned short age) {
		this->m_name = name;
		this->m_age = age;
		cout << "Constructor using this pointer called" << endl;
	}
	*/
	//Default constructor
	Human() {
		cout << "Default constructor called" << endl;
		m_count++;
	}
	//Constructor with member initializer list (preferred)
	Human(string name, age_t age) : m_name(name), m_age(age) {
		m_count++;
		cout << "Constructor with member initializer list called" << endl;
	}
	//Destructor deletes the object when it goes out of scope (optional)
	~Human() {
		m_count--;
		cout << "Destructor called" << endl;
	}

	static int getCount() {
		return m_count;
	}
	string getName() {
		return m_name;
	}
	age_t getAge() {
		return m_age;
	}
	//Contained inside Human.cpp
	void setAge(age_t age);
	//Using protected so Student.h can access the member variables
protected:
	//Using m_ prefix for member variables
	//Setting m_age to 0 by default (prevents build errors, can use NULL but 0 is preferred)
	string m_name;
	age_t m_age = 0;
	static int m_count;
	static const float m_tax;
};

void func();

