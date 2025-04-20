#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(float radius) {
	m_radius = radius;
}

Circle::~Circle() {}

float Circle::Area() {
	return 3.14f * m_radius * m_radius;
}

float Circle::GetRadius() {
	return m_radius;
}

void Circle::SetRadius(float radius) {
	m_radius = radius;
}