
#pragma once
#include "Human.h"
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
	Type getType() override{
		return WORKER;
	}

private:
	float m_salary = 0.0f;
	bool m_hasCar;
};
