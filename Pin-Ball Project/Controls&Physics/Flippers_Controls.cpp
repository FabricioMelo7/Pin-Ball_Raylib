#include "Flippers_Controls.h"

Flippers_Controls::Flippers_Controls(){}

//void Flippers_Controls::SetCorners(Vector2 corners[], int size, Rectangle& boundBox)
//{
//	corners[0].x = boundBox.x;
//	corners[0].y = boundBox.y;
//
//	corners[1].x = boundBox.x + boundBox.width;
//	corners[1].y = boundBox.y;
//
//	corners[2].x = boundBox.x;
//	corners[2].y = boundBox.y + boundBox.height;
//
//	corners[3].x = boundBox.x + boundBox.width;
//	corners[3].y = boundBox.y + boundBox.height;
//}
//
//Rectangle Flippers_Controls::RotateBoundignBox(Rectangle boundBox, float angle, Vector2 pivot)
//{
//	Rectangle newRec;
//
//	Vector2 corners[4];
//	float s = sin(angle * DEG2RAD);
//	float c = cos(angle * DEG2RAD);
//
//	//Bounding box corners
//	SetCorners(corners, 4, boundBox);	
//	
//	//New BoundingBox
//	float minX = FLT_MAX;
//	float minY = FLT_MAX;
//	float maxX = -FLT_MAX;
//	float maxY = -FLT_MAX;
//
//	//Transforme corners around the pivot
//	/*for (size_t i = 0; i < 4; i++)
//	{
//		float x0ld = corners[i].x - pivot.x;
//		float y0ld = corners[i].y - pivot.y;
//
//		corners[i].x = c * x0ld - s * y0ld + pivot.x;
//		corners[i].y = s * x0ld + c * y0ld + pivot.y;
//	}*/
//
//	for (int i = 0; i < 4; i++) 
//	{
//		float xNew = corners[i].x * c - corners[i].y * s + pivot.x;
//		float yNew = corners[i].x * s + corners[i].y * c + pivot.y;
//
//		minX = fmin(minX, xNew);
//		minY = fmin(minY, yNew);
//		maxX = fmax(maxX, xNew);
//		maxY = fmax(maxY, yNew);
//	}
//
//	for (size_t i = 0; i < 4; i++)
//	{
//		if (corners[i].x < minX) minX = corners[i].x;
//		if (corners[i].y < minY) minY = corners[i].y;
//		if (corners[i].x > maxX) maxX = corners[i].x;
//		if (corners[i].y > maxY) maxY = corners[i].y;
//	}
//
//	newRec = { minX, minY, maxX - minX, maxY - minY };
//	return newRec;
//}
//
//void Flippers_Controls::DrawFlipperBoundingBox(Flippers* flipper)
//{
//	Rectangle bounds = { flipper->m_flipperRec.x, flipper->m_flipperRec.y, flipper->m_flipperRec.width, flipper->m_flipperRec.height };
//	Vector2 pivot = { flipper->m_flipperRec.x + flipper->m_flipperRec.width, flipper->m_flipperRec.y + flipper->m_flipperRec.height / 2};
//
//	//Rotate bounding box
//	Rectangle rotatedBoundBox = RotateBoundignBox(bounds, flipper->m_flipperAngle, pivot);
//
//	DrawRectangleLines(rotatedBoundBox.x, rotatedBoundBox.y, rotatedBoundBox.width, rotatedBoundBox.height, GREEN);
//
//	DrawCircleV(pivot, 5, YELLOW);
//}

void Flippers_Controls::UpdateFlipper(Flippers* flipper, float deltaTime)
{
	flipper->dv =
	{
		flipper->force.x / flipper->mass,
		flipper->force.y / flipper->mass
	};

	flipper->v.x += flipper->dv.x * deltaTime;
	flipper->v.y += flipper->dv.y * deltaTime;

	flipper->dr.x = flipper->v.x * deltaTime + 0.5f * flipper->dv.x * deltaTime * deltaTime;
	flipper->dr.y = flipper->v.y * deltaTime + 0.5f * flipper->dv.y * deltaTime * deltaTime;

	flipper->m_flipperAngle += flipper->dr.x;

	flipper->force = { 0.0f, 0.0f };
}

void Flippers_Controls::ApplyLeftFlipperForce(Flippers* flipper)
{
	Vector2 forceDirection =
	{
		static_cast<float>(cos(flipper->m_flipperAngle * DEG2RAD)),
		static_cast<float>(sin(flipper->m_flipperAngle * DEG2RAD))
	};

	flipper->force =
	{
		flipper->m_power_value * forceDirection.x,
		flipper->m_power_value * forceDirection.y
	};
}

void Flippers_Controls::ApplyRightFlipperForce(Flippers* flipper)
{
	Vector2 forceDirection =
	{
		static_cast<float>(cos(flipper->m_flipperAngle * DEG2RAD)),
		static_cast<float>(sin(flipper->m_flipperAngle * DEG2RAD))
	};

	flipper->force =
	{
		flipper->m_power_value * forceDirection.x,
		flipper->m_power_value * forceDirection.y
	};
}

void Flippers_Controls::HandleLeftInput(Flippers* flipper, float deltaTime)
{
	if ( IsKeyDown(KEY_LEFT) && flipper->m_flipperAngle > -30.0f)
	{
		ApplyLeftFlipperForce(flipper);	
		Update(flipper, deltaTime);	

		if (flipper->m_flipperAngle < -30.0f) // safety - Makes sure the angle does not exceed -30
		{
			flipper->m_flipperAngle = -30.0f;
		}
	}

	if(IsKeyDown(KEY_LEFT) && flipper->m_flipperAngle == -30.0f)
	{
		flipper->m_flipperAngle = -30.0f;
		ResetFlipperValues(flipper);
	}

	else if (flipper->m_flipperAngle < 45.0f)
	{
		flipper->m_flipperAngle += 5;   // SPEED WHICH FLIPPER GOES BACK TO ITS ORIGINAL POSITON
	}
}

void Flippers_Controls::HandleRightInput(Flippers* flipper, float deltaTime)
{
	if (IsKeyDown(KEY_RIGHT) && flipper->m_flipperAngle < 30.0f)
	{
		ApplyRightFlipperForce(flipper);
		Update(flipper, deltaTime);

		if (flipper->m_flipperAngle > 30.0f)  //safety - Makes sure the angle does not exceed 30
		{
			flipper->m_flipperAngle = 30.0f;
		}
	}

	if (IsKeyDown(KEY_RIGHT) && flipper->m_flipperAngle == 30)
	{
		flipper->m_flipperAngle == 30;
		ResetFlipperValues(flipper);
	}

	else if (flipper->m_flipperAngle > -45)
	{
		flipper->m_flipperAngle -= 5;  // SPEED WHICH FLIPPER GOES BACK TO ITS ORIGINAL POSITON
	}
}

void Flippers_Controls::PlayerInput(std::vector<Flippers*> flippers, float deltaTime) 
{
	for (size_t i = 0; i < flippers.size(); i++)
	{
		switch (flippers[i]->side)
		{
		case Flippers_Enums::RightSideFlipper:	
			HandleRightInput(flippers[i], deltaTime);			
			break;

		case Flippers_Enums::LeftSideFlipper:
			HandleLeftInput(flippers[i], deltaTime);
			break;
		}
	}
}

void Flippers_Controls::Update(Flippers* flipper, float deltaTime)
{
	UpdateFlipper(flipper, deltaTime);
	//DrawFlipperBoundingBox(flipper);
}

void Flippers_Controls::ResetFlipperValues(Flippers* flipper)
{
	flipper->dr = { 0.0f, 0.0f };
	flipper->v = { 0.0f, 0.0f };
	flipper->dv = { 0.0f, 0.0f };	
}
