#pragma once

#ifndef FLIPPERS_H
#define FLIPPER_H

#include <raylib.h>
#include "../Enums/Flippers_Enums.h"

class Flippers
{
public:
	Flippers(Vector2 originPosition, float tableWidth, float tableHeight, Flippers_Enums side, float power);	
	
	Flippers_Enums side;

	float m_flipperWidth;
	float m_flipperHeight;
	Vector2 m_pivotPoint;

	//Physics
	const float m_power_value = 70.0f;
	//Vector2 m_Power = { 0.0f, 0.0f };
	float mass = 0.1;
	Vector2 force = { 0.0f, 0.0f };
	float m_flipperAngle;
	Vector2 dr = { 0.0f, 0.0f };
	Vector2 v = { 0.0f, 0.0f };
	Vector2 dv = { 0.0f, 0.0f };	

	Rectangle m_flipperRec;
	void Draw();

private:
	float SetFlipperAngle(Flippers_Enums side);
	void InitFlipper(Vector2 originPosition, float tableWidth, float tableHeight, Flippers_Enums);
	void SetLeftFlipper(Vector2 originPosition, float tableWidth, float tableHeight);
	void SetRightFlipper(Vector2 originPosition, float tableWidth, float tableHeight);
};

#endif

