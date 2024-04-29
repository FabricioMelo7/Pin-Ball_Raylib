#include "Gravity.h"

Vector2 Gravity = { 0.0f, -15.6f };

Vector2 Euler(Vector2 a, float h)
{
	a = { a.x, a.y * h };
	return a;
}

void SetForce(Ball& ball)
{
	ball.m_force.x = ball.m_Momentum.x * ball.mass;
	ball.m_force.y = (Gravity.y + ball.m_Momentum.y) * ball.mass;
}

void ApplyEuler(Ball& ball, float deltaTime)
{
	Vector2 x;
	ball.dv = Euler(x =
		{
			ball.m_force.x / ball.mass,
			ball.m_force.y * 1 / ball.mass
		}, deltaTime);

	ball.v = { ball.v.x + ball.dv.x, ball.v.y + ball.dv.y };
	ball.dr = { ball.v.x * deltaTime, ball.v.y * deltaTime };
	ball.m_bounds = { ball.m_bounds.x + ball.dr.x, ball.m_bounds.y - ball.dr.y };
}

void ApplyGravity(Ball& ball, float deltaTime)
{
	SetForce(ball);
	ApplyEuler(ball, deltaTime);
}

