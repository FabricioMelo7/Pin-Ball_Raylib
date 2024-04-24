// Pin-Ball.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Entities/Ball.h"
#include "Entities/GameTable.h"
#include "Entities/Flippers.h"
#include "Controls&Physics/Flippers_Controls.h"
#include <vector>

std::vector<Flippers*> flipperList;

int main()
{
	const int windowWidth = 720;
	const int windowHeight = 1000;	

	InitWindow(windowWidth, windowHeight, "PinBallTable");

	float DeltaTime = 0.06;
	//MoonSphere ball;
	GameTable table(windowWidth, windowHeight);
	Flippers leftFlipper(table.origin, table.width, table.height, Flippers_Enums::LeftSideFlipper, -70.0f);
	Flippers rightFlipper(table.origin, table.width, table.height, Flippers_Enums::RightSideFlipper, 70.0f);
	flipperList.push_back(&leftFlipper);
	flipperList.push_back(&rightFlipper);	
	
	Flippers_Controls flipperControl;
	
	//Vector3 pos = { 0.0f, 0.0f , 0.0f };
	//BoundingBox bounds = GetMeshBoundingBox(ball.moon.meshes[0]);

	SetTargetFPS(60); 
	
	//MAIN GAME LOOP!
	while (!WindowShouldClose())
	{		
		BeginDrawing();		
		ClearBackground(DARKGRAY);
		
		//table.PlayerInput();
		
		table.Draw();		

		flipperControl.PlayerInput(flipperList, DeltaTime);
		leftFlipper.Draw();		
		rightFlipper.Draw();

		//DrawModel(ball.moon, pos, 1.0f, WHITE);
		
		//DrawBoundingBox(bounds, GREEN);		

		DrawFPS(10, 10);
		EndDrawing();
	}

	//UnloadTexture(ball.tex);
	//UnloadModel(ball.moon);
	CloseWindow();

	return 0;
}

