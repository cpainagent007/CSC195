#include "Circle.h"

bool Circle::ColorCheck(Color check) {
	return this->getColor().r == check.r && this->getColor().g == check.g && this->getColor().b == check.b && this->getColor().a == check.a;
}

void Circle::update() {
	//
}

void Circle::draw() {
	DrawCircleV(m_position, m_size, m_color);
}

Circle::Type Circle::getType() {
	return Type::Circle;
}