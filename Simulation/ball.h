#pragma once
class Circle;

class Ball
{
public:
	Ball(float x, float y, float radius, float speed = 0.008f) {
		m_x = x;
		m_y = y;
		m_radius = radius;
		m_speed = speed;
	}

	void Draw();
	void Tick(Circle* circle);

private:
	float gravity = -9.81f;
	float m_x, m_y;

	float m_radius;
	float m_speed;
	
	float m_vx = 0.0001f;
	float m_vy = 0.0f;

	void AddForce(float x, float y);
	void ResetVelocity();

};

