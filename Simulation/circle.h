#pragma once
#include "ball.h"

class Circle {
public:
	Circle(float x, float y, float radius, float width) {
		m_x = x;
		m_y = y;
		m_radius = radius;
		m_width = width;
	}
	
	float m_x, m_y;
	float m_radius;
	float m_width;
	
	void Draw();
	void Tick();
	void SetRadius(float radius);

private:

	void DrawOuter();
	void DrawInner();
};

