
#include "Student.h"
#include "Console.h"
#include <iostream>

using namespace std;

void Student::Read() {
	Human::Read();
	cout << "GPA: ";
	m_gpa = getData<float>();
}

void Student::Write() {
	Human::Write();
	cout << "GPA: " << m_gpa << endl;
}