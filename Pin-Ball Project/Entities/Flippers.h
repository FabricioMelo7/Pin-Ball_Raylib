#pragma once

#ifndef FLIPPERS_H
#define FLIPPER_H

#include <raylib.h>
#include "Flippers_Enums.h"

class Flippers
{
public:
	Flippers(Vector2 originPosition, float tableWidth, float tableHeight, Flippers_Enums side);
	
	float m_flipperAngle;
	float m_flipperWidth;
	float m_flipperHeight;
	Vector2 m_pivotPoint;

	Rectangle m_flipperRec;
	void Draw();

private:
	float SetFlipperAngle(Flippers_Enums side);
	void InitFlipper(Vector2 originPosition, float tableWidth, float tableHeight, Flippers_Enums);
	void SetLeftFlipper(Vector2 originPosition, float tableWidth, float tableHeight);
	void SetRightFlipper(Vector2 originPosition, float tableWidth, float tableHeight);
};

#endif

