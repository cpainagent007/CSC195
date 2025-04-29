#include "Triangle.h"

bool Triangle::ColorCheck(Color check) {
	return this->getColor().r == check.r && this->getColor().g == check.g && this->getColor().b == check.b && this->getColor().a == check.a;
}

void Triangle::update() {
	//
}

void Triangle::draw() {
	Vector2 positionBL = { m_position.x - 50, m_position.y + 50 };
	Vector2 positionBR = { m_position.x + 50, m_position.y + 50 };
	Vector2 positionTop = { m_position.x, m_position.y - 50 };
	DrawTriangle(positionTop, positionBL, positionBR, m_color);
}

Triangle::Type Triangle::getType() {
	return Type::Triangle;
}