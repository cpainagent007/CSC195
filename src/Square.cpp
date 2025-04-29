#include "Square.h"

bool Square::ColorCheck(Color check) {
	return this->getColor().r == check.r && this->getColor().g == check.g && this->getColor().b == check.b && this->getColor().a == check.a;
}

void Square::update() {
	//
}

void Square::draw() {
	DrawRectangleV(m_position, { m_size, m_size }, m_color);
}

Square::Type Square::getType() {
	return Type::Square;
}