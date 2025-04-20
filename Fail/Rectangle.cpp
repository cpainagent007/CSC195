#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(float width, float height) {
	m_width = width;
	m_height = height;
}

Rectangle::~Rectangle() {}

float Rectangle::Area() {
	return m_width * m_height;
}