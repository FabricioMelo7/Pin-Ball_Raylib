// Pin-Ball.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Entities/Ball.h"

void CameraSetUp(Camera& cam)
{
	cam.position.x = 10.0f;
	cam.position.y = 10.0f;
	cam.position.z = 10.0f;
	cam.target.x = 0.0f;
	cam.target.y = 0.0f;
	cam.target.z = 0.0f;
	cam.up.x = 0.0f;
	cam.up.y = 1.0f;
	cam.up.z = 0.0f;
	cam.fovy = 50.0f;
	cam.projection = CAMERA_PERSPECTIVE;
}

int main()
{
	InitWindow(1280, 720, "PinBallTable");

	MoonSphere ball;
		
	Camera cam = { 0 };
	CameraSetUp(cam);	
	Vector3 pos = { 0.0f, 0.0f , 0.0f };
	BoundingBox bounds = GetMeshBoundingBox(ball.moon.meshes[0]);

	SetTargetFPS(60); 
	

	while (!WindowShouldClose())
	{		
		BeginDrawing();

		ClearBackground(DARKGRAY);
		BeginMode3D(cam);
		DrawModel(ball.moon, pos, 1.0f, WHITE);
		DrawGrid(20, 5.0f);
		DrawBoundingBox(bounds, GREEN);


		EndMode3D();
		DrawText("Loading...", 10, GetScreenHeight() - 25, -25, DARKPURPLE);
		DrawFPS(10, 10);
		EndDrawing();
	}

	UnloadTexture(ball.tex);
	UnloadModel(ball.moon);
	CloseWindow();

	return 0;
}

