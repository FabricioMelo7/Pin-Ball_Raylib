#include "Ball.h"

Ball::Ball(float x, float y, float radius, Color color) :m_radius(radius), m_color(color)
{
	m_bounds.x = x - radius;
	m_bounds.y = y - radius;
	m_bounds.width = 2 * radius;
	m_bounds.height = 2 * radius;
}

void Ball::Draw()
{
	DrawCircle(m_bounds.x + m_radius, m_bounds.y + m_radius, m_radius, m_color);
}



