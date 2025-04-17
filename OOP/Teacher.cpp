
#include "Teacher.h"
#include "Console.h"
#include <iostream>

using namespace std;

void Teacher::Read() {
	Human::Read();
	cout << "Class name: ";
	cin >> m_className;
	cout << "Classroom: ";
	m_classroom = getData<unsigned short>();
}
void Teacher::Write() {
	Human::Write();
	cout << "Class name: " << m_className << endl;
	cout << "Classroom: " << m_classroom << endl;
}