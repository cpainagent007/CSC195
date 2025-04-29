#include "raylib.h"
#pragma once

class Shape {
public:
	enum class Type {
		Circle,
		Square,
		Triangle,
		Image
	};

public:
	Shape() = default;

	// Assigning size and color in the parameters lets them have default values if not provided at the time of construction
	Shape(const Vector2 position, float size = 20.0f, const Color& color = WHITE) :
		m_position{ position }, m_size{ size }, m_color{ color } {
	}

	virtual bool ColorCheck(Color check) = 0;
	virtual void update() {};
	virtual void draw() = 0;
	virtual Type getType() = 0;

	const Vector2& getPosition() {
		return m_position;
	}
	void setPosition(const Vector2& position) {
		m_position = position;
	}

	float getSize() const {
		return m_size;
	}
	void setSize(float size) {
		m_size = size;
	}

	const Color& getColor() const {
		return m_color;
	}
	void setColor(const Color& color) {
		m_color = color;
	}

	virtual void update(float deltaTime) {};

protected:
	Vector2 m_position = { 0.0f, 0.0f };
	float m_size = 20.0f;
	Color m_color = WHITE;


private:
};