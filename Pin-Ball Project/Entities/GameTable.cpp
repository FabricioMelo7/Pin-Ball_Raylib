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

	//left Flipper
	leftFlipper = 
	{ 
		origin.x + (width / 2) - 80, 
		origin.y + height - flipperHeight - 20,
		flipperWidth, 
		flipperHeight 
	};

	leftFlipperAngle = 45.0f;

	leftPivot = //This sets the rotation pivot to the left middle point.	
	{
		0,
		leftFlipper.height / 2
	};

	//Right Flipper
	rightFlipper = 
	{
		origin.x + (width / 2) + 60, 
		origin.y + height - flipperHeight - 20, 
		flipperWidth, 
		flipperHeight 
	};

	rightFlipperAngle = -45.0f; 

	rightPivot = //This sets the rotation pivot to the right middle point.	
	{
		rightFlipper.width,                   
		rightFlipper.height / 2
	};
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

	//DrawRectangle(leftFlipper.x, leftFlipper.y, flipperWidth, flipperHeight, DARKGREEN);
	
	DrawRectanglePro(leftFlipper, leftPivot, leftFlipperAngle, DARKGREEN);
	DrawRectanglePro(rightFlipper, rightPivot, rightFlipperAngle, DARKGREEN);	

	DrawCircle(origin.x, origin.y, 10, PURPLE);

	EndDrawing;
}

void GameTable::PlayerInput()
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
}
