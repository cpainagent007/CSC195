#include "Shape.h"
#pragma once
#include <iostream>

using namespace std;

class Circle : public Shape {
public:
	Circle(float radius);
	~Circle();
	float Area() override;
	void SetRadius(float radius);
	float GetRadius();
private:
	float m_radius;
};
