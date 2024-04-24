#include "Flippers.h"

float Flippers::SetFlipperAngle(Flippers_Enums side)
{
	switch (side)
	{
	case Flippers_Enums::RightSideFlipper:
		return -45.0f;
		break;

	case Flippers_Enums::LeftSideFlipper:
		return 45.0f;
		break;
	}
}

Flippers::Flippers(Vector2 originPosition, float tableWidth, float tableHeight, Flippers_Enums side, float power) :m_power_value(power), side(side)
{
	m_flipperWidth = 60;
	m_flipperHeight = 10;
	m_flipperAngle = SetFlipperAngle(side);

	InitFlipper(originPosition, tableWidth, tableHeight, side);	
}

void Flippers::SetLeftFlipper(Vector2 originPosition, float tableWidth, float tableHeight)
{
	m_flipperRec =
	{
		originPosition.x + (tableWidth / 2) - 80,
		originPosition.y + tableHeight - m_flipperHeight - 20,
		m_flipperWidth,
		m_flipperHeight
	};

	m_pivotPoint =
	{
		0,
		m_flipperRec.height / 2
	};	
}

void Flippers::SetRightFlipper(Vector2 originPosition, float tableWidth, float tableHeight)
{
	m_flipperRec =
	{
		originPosition.x + (tableWidth / 2) + 60,
		originPosition.y + (tableHeight - m_flipperHeight) - 20,
		m_flipperWidth,
		m_flipperHeight
	};

	m_pivotPoint =
	{
		m_flipperRec.width,
		m_flipperHeight / 2
	};
}

void Flippers::InitFlipper(Vector2 originPosition, float tableWidth, float tableHeight, Flippers_Enums side)
{
	switch (side)
	{
	case Flippers_Enums::RightSideFlipper:
		SetRightFlipper(originPosition, tableWidth, tableHeight);
		break;

	case Flippers_Enums::LeftSideFlipper:
		SetLeftFlipper(originPosition, tableWidth, tableHeight);
		break;
	}	
}

void Flippers::Draw()
{
	DrawRectanglePro(m_flipperRec, m_pivotPoint, m_flipperAngle, DARKGREEN);
}