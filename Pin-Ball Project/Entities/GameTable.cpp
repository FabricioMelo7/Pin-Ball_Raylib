#include "GameTable.h"

GameTable::GameTable()
{
	initTable();
	initBumpers();
}

GameTable::~GameTable()
{
	UnloadModel(tableModel);
	UnloadModel(borderFrontModel);
	UnloadModel(borderBackModel);
	UnloadModel(borderLeftModel);
	UnloadModel(borderRightModel);

	for (int i = 0; i < 3; i++) {
		UnloadModel(bumperModel[i]);
	}
}

void GameTable::initTable()
{
	// base table
	Mesh tableMesh = GenMeshCube(5.0f, 0.1f, 10.0f);
	tableModel = LoadModelFromMesh(tableMesh);
	tablePosition = { 0.0f, 0.0f, 0.0f };

	// separate models for each border
	Mesh borderMesh = GenMeshCube(5.0f, 0.5f, 0.5f);
	borderFrontModel = LoadModelFromMesh(borderMesh);
	borderBackModel = LoadModelFromMesh(borderMesh);
	borderLeftModel = LoadModelFromMesh(GenMeshCube(0.5f, 0.5f, 10.0f));
	borderRightModel = LoadModelFromMesh(GenMeshCube(0.5f, 0.5f, 10.0f));
}

void GameTable::initBumpers()
{
	for (size_t i = 0; i < 3; i++)
	{
		bumperMesh[i] = GenMeshSphere(0.5f, 32.0f, 32.0f);
		bumperModel[i] = LoadModelFromMesh(bumperMesh[i]);
		bumperPosition[i] = { (float)(i - 1) * 2.5f, 1.0f, 0.0f };
	}
}

void GameTable::Draw()
{
	DrawModel(tableModel, tablePosition, 1.0f, RED);
	DrawModel(borderFrontModel, { 0, 0.25f, -4.75f }, 1.0f, WHITE);
	DrawModel(borderBackModel, { 0, 0.25f, 4.75f }, 1.0f, WHITE);
	DrawModel(borderLeftModel, { -2.25f, 0.25f, 0 }, 1.0f, WHITE);
	DrawModel(borderRightModel, { 2.25f, 0.25f, 0 }, 1.0f, WHITE);

	for (int i = 0; i < 3; i++) {
		DrawModel(bumperModel[i], bumperPosition[i], 1.0f, GREEN);
	}
}