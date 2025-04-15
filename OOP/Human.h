
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

	//Enumeration (can also explicitly assign values to the enumerators)
	enum Type {
		STUDENT,
		WORKER,
		TEACHER
	};
	//Using class keyword to define a nested enumeration
	//Colon with datatype indicates the underlying type of the enum
	enum class Type2 : int{
		STUDENT,
		WORKER,
		TEACHER
	};
	//Enum values specified by the class keyword
	Type type = STUDENT;
	Type type2 = Type::STUDENT;
	//Casting enum class to int (C method)
	int type3 = (int)Type::STUDENT;
	//Casting enum class to int (C++ method)
	int type4 = static_cast<int>(Type::STUDENT);

	//Virtual keyword and no body (pure virtual) means the child classes must implement it and the method in Human.h is abstract
	virtual Type getType() = 0;

	//Virtual keyword but contains body means the child classes can override it, but default is used if not specifically overridden
	virtual void work() {
		cout << "Human Working" << endl;
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

