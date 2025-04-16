
#include "Student.h"
#include <iostream>

using namespace std;

void Student::Read() {
	Human::Read();
	cout << "GPA: ";
	cin >> m_gpa;
}

void Student::Write() {
	Human::Write();
	cout << "GPA: " << m_gpa << endl;
}