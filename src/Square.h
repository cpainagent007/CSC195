#include "Shape.h"
#pragma once

class Square : public Shape {
public:
	bool ColorCheck(Color check) override;
	Square() = default;
	Square(const Vector2 position, float size = 20.0f, const Color& color = WHITE) :
		Shape(position, size, color) {
	}
	void update() override;
	void draw() override;
	Type getType() override;
};
