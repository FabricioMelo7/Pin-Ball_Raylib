// Pin-Ball.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Entities/Ball.h"
#include "Entities/GameTable.h"

int main()
{
	const int windowWidth = 720;
	const int windowHeight = 1000;

	InitWindow(windowWidth, windowHeight, "PinBallTable");

	MoonSphere ball;
	GameTable table(windowWidth, windowHeight);
		
	
	
	//Vector3 pos = { 0.0f, 0.0f , 0.0f };
	//BoundingBox bounds = GetMeshBoundingBox(ball.moon.meshes[0]);

	SetTargetFPS(60); 
	

	while (!WindowShouldClose())
	{		
		BeginDrawing();		
		ClearBackground(DARKGRAY);
		
		table.PlayerInput();
		
		table.Draw();
		//DrawModel(ball.moon, pos, 1.0f, WHITE);
		
		//DrawBoundingBox(bounds, GREEN);		

		DrawText("Loading...", 10, GetScreenHeight() - 25, -25, DARKPURPLE);
		DrawFPS(10, 10);
		EndDrawing();
	}

	UnloadTexture(ball.tex);
	UnloadModel(ball.moon);
	CloseWindow();

	return 0;
}

