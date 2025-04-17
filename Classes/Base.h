#pragma once
#include <iostream>

using namespace std;

class BaseClassName
{
public:
	enum class eType {
		CAT,
		DOG,
		BIRD
	};

	virtual void Read(ostream& ostream, istream& istream) {
		ostream << "Enter name: ";
		istream >> m_name;
		ostream << "Enter age: ";
		istream >> m_age;
	}
	virtual void Write(ostream& ostream) {
		ostream << "Name: " << m_name << endl;
		ostream << "Age: " << m_age << endl;
	}

	string GetName() {
		return m_name;
	}
	virtual eType GetType() = 0;
private:
	string m_name;
	unsigned int m_age;
};
