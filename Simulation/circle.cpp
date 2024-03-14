#include "circle.h"
#include <GLFW/glfw3.h>
#include <cmath>

void Circle::SetRadius(float radius) {
	m_radius = radius;
}

void Circle::Draw() {
	DrawOuter();
	DrawInner();
}

void Circle::DrawOuter() {
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++) {
		float theta = i * 3.14159f / 180;
		float cosTheta = cos(theta);
		float sinTheta = sin(theta);
		
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(m_x + m_radius * cosTheta, m_y + m_radius * sinTheta);
		
	}
	glEnd();
}

void Circle::DrawInner() {
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++) {
		float theta = i * 3.14159f / 180;
		float cosTheta = cos(theta);
		float sinTheta = sin(theta);

		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(m_x + (m_radius - m_width) * cosTheta, m_y + (m_radius - m_width) * sinTheta);

	}
	glEnd();
		
}

void Circle::Tick() {
	
}