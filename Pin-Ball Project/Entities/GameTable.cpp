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
	
}

void GameTable::initTable()
{
	//Temporary bumpers, used to have a better layout idea
	bumper[0] = { origin.x + width / 3, origin.y + height / 2 };
	bumper[1] = { origin.x + width / 2, origin.y + height / 3 };
	bumper[2] = { origin.x + 2 * width / 3, origin.y + 2 * height / 3 };

	// Setting up initial flipper's layout
	flipperWidth = 60;
	flipperHeight = 10;
	leftFlipper = { origin.x + 100, origin.y + height - 20, flipperWidth, flipperHeight };
	rightFlipper = { origin.x + width - 100 - flipperWidth, origin.y + height - 20, flipperWidth, flipperHeight };
}

void GameTable::Draw()
{
	BeginDrawing();
	ClearBackground(DARKGRAY);

	// Outer borders of the pinball table
	DrawRectangleLines(origin.x, origin.y, width, height, BLACK); // Main border
	// Inner borders for a depth effect
	DrawRectangleLines(origin.x + 5, origin.y + 5, width - 10, height - 10, BLACK);

	for (size_t i = 0; i < 3; i++)
	{
		DrawCircle(bumper[i].x, bumper[i].y, bumperRadius, RED);
	}

	DrawRectangleRec(leftFlipper, GREEN);
	DrawRectangleRec(rightFlipper, GREEN);

	EndDrawing;
}

void GameTable::Update()
{
	// Flipper movement
}
