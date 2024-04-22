#pragma once
#ifndef GAMETABLE_H
#define GAMETABLE_H

#include <raylib.h>

class GameTable
{
public:
	GameTable(int windowWidth, int windowHeight);
	~GameTable();

	void Draw();
    void Update();

private:
	Vector2 origin;
	float width, height;

	Vector2 bumper[3];
	float bumperRadius;

	Rectangle leftFlipper, rightFlipper;
	float flipperWidth, flipperHeight;

	void initTable();

};

#endif // GAMETABLE_H

