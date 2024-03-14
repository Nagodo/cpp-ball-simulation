#include "ball.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include "circle.h"


void Ball::Draw() {
	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++) {
		float theta = i * 3.14159f / 180;
		float cosTheta = cos(theta);
		float sinTheta = sin(theta);

		glColor3f(0.0f, 0.0f, 0.5f);
		glVertex2f(m_x + m_radius * cosTheta, m_y + m_radius * sinTheta);

	}
	glEnd();
}

void Ball::Tick(Circle* circle) {

	bool collideWithCircle = false;
	float distance = sqrt((m_x - circle->m_x) * (m_x - circle->m_x) + (m_y - circle->m_y) * (m_y - circle->m_y));
	if (distance > circle->m_radius - m_radius - circle->m_width) {
		collideWithCircle = true;
	}

	if (collideWithCircle) {
		
		ResetVelocity();

		//Get the angle of the collision
		float angle = atan2(m_y - circle->m_y, m_x - circle->m_x);
		
		//Add in the reflection angless
		angle += 3.14159f;
		
		//Add in the velocity
		AddForce(cos(angle) * m_speed, sin(angle) * m_speed * 1.4f);

		if (circle->m_radius <= m_radius + circle->m_width) {
			circle->SetRadius(m_radius + circle->m_width);
			return;
		}


		circle->SetRadius(circle->m_radius - 0.002f);

	}
	m_vy += gravity * 0.00001f;

	
	if (abs(m_vx) < 0.001f) {
		m_vx += 0.001f;
	}

	m_x += m_vx;
	m_y += m_vy;
}

void Ball::AddForce(float x, float y) {
	m_vx += x;
	m_vy += y;
}

void Ball::ResetVelocity() {
	m_vx = 0.0f;
	m_vy = 0.0f;
}