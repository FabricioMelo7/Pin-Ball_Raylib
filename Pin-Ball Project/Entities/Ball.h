#pragma once
#ifndef  BALL_H
#define BALL_H

#include <raylib.h>
#include <iostream>

class Ball
{
public:
	Rectangle m_bounds;	
	float m_radius;
	Color m_color;

	//Physics
	const float mass = 1.0f;
	Vector2 m_force = { 0.0f, 0.0f };
	Vector2 position = { 0.0f, 0.0f }; // Might not need this, could use m_bounds postion instead ??
	Vector2 dr = { 0.0f, 0.0f }; //Position changed within the frame
	Vector2 v = { 0.0f, 0.0f }; //Current velocity
	Vector2 dv = { 0.0f, 0.0f }; //Speed changed within the frame
	Vector2 m_Momentum = { 0.0f, 0.0f }; // power once the flipper hits the ball


	Ball(float x, float y, float radius, Color color);
	void Draw();
};

#endif // ! BALL_H

