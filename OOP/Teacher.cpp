
#include "Teacher.h"
#include <iostream>

using namespace std;

void Teacher::Read() {
	Human::Read();
	cout << "Class name: ";
	cin >> m_className;
	cout << "Classroom: ";
	cin >> m_classroom;
}
void Teacher::Write() {
	Human::Write();
	cout << "Class name: " << m_className << endl;
	cout << "Classroom: " << m_classroom << endl;
}