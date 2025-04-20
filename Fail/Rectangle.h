#include "Shape.h"
#pragma once
#include <iostream>

using namespace std;

class Rectangle : public Shape {
public:
	Rectangle(float width, float height);
	~Rectangle();
	float Area() override;
private:
	float m_width;
	float m_height;
};
