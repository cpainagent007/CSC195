
#include "Human.h"
#pragma once
#include <iostream>

using namespace std;

class Worker : public Human {
public:
	Worker() {
		cout << "Worker default constructor called" << endl;
	}
	Worker(string name, age_t age, float salary, bool hasCar) :
		Human{ name, age }, m_salary(salary), m_hasCar(hasCar){
		cout << "Worker parameter constructor called" << endl;
	}

	float getSalary() {
		return m_salary;
	}
	void setSalary(float salary) {
		m_salary = salary;
	}

private:
	float m_salary = 0.0f;
	bool m_hasCar;
};
