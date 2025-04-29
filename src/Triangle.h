#include "Shape.h"
#pragma once

class Triangle : public Shape {
public:
	bool ColorCheck(Color check) override;
	Triangle() = default;
	Triangle(const Vector2 position, float size = 20.0f, const Color& color = WHITE) :
		Shape(position, size, color) {

	}
	void update() override;
	void draw() override;
	Type getType() override;
};
