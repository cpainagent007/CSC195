#include "Shape.h"
#pragma once

class Circle : public Shape {
public:
	bool ColorCheck(Color check) override;
	Circle() = default;
	Circle(const Vector2 position, float size = 20.0f, const Color& color = WHITE) :
		Shape(position, size, color) {
	}
	void update() override;
	void draw() override;
	Type getType() override;
};
