#include "GameTable.h"

GameTable::GameTable(int windowWidth, int windowHeight)
{	
	width = 500.0f;
	height = 900.0f;
	origin.x = (windowWidth - width) / 2;
	origin.y = (windowHeight - height) / 2;
	bumperRadius = 20;
	initTable();
}

GameTable::~GameTable()
{
	//TO-DO
}

void GameTable::initTable()
{
	//Temporary bumpers, used to have a better layout idea
	bumper[0] = { origin.x + width / 3, origin.y + height / 2 };
	bumper[1] = { origin.x + width / 2, origin.y + height / 3 };
	bumper[2] = { origin.x + 2 * width / 3, origin.y + 2 * height / 3 };

	flipperWidth = 60;
	flipperHeight = 10;	
}

void GameTable::Draw()
{	
	ClearBackground(DARKGRAY);

	// Outer borders of the pinball table
	DrawRectangleLines(origin.x, origin.y, width, height, BLACK); // Main border
	// Inner borders for a depth effect
	DrawRectangleLines(origin.x + 5, origin.y + 5, width - 10, height - 10, BLACK);

	for (size_t i = 0; i < 3; i++)
	{
		DrawCircle(bumper[i].x, bumper[i].y, bumperRadius, RED);
	}

	DrawCircle(origin.x, origin.y, 10, PURPLE); // JUST FOR QUICK REFERENCE, Should get removed later on

	EndDrawing;
}

/*void GameTable::PlayerInput()
{
	if (IsKeyDown(KEY_LEFT) && leftFlipperAngle > -20)
	{
		leftFlipperAngle -= 10;
	}

	if (IsKeyDown(KEY_LEFT) && leftFlipperAngle == -20)
	{
		leftFlipperAngle = -20;
	}
	else if(leftFlipperAngle < 45)
	{
		leftFlipperAngle += 5;
	}

	if(IsKeyDown(KEY_RIGHT) && rightFlipperAngle < 20)
	{
		rightFlipperAngle += 10;
	}

	if (IsKeyDown(KEY_RIGHT) && rightFlipperAngle == 20)
	{
		rightFlipperAngle = 20;
	}
	else if (rightFlipperAngle > -45)
	{
		rightFlipperAngle -= 5;
	}	
}*/
