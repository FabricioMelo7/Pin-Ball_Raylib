#include "Flippers_Collision.h"

Flippers_Collision::Flippers_Collision(){}

Rectangle Flippers_Collision::GetRotatedFlipperBoundingBox(Rectangle flipperRec, float angle, Vector2 pivot)
{
	//COS & SIN

	float s = sin(angle * DEG2RAD);
	float c = cos(angle * DEG2RAD);

	//Flipper Corners around pivot point

	Vector2 corners[4];
	corners[0] = { flipperRec.x - pivot.x, flipperRec.y - pivot.y };
	corners[1] = { flipperRec.x + flipperRec.width - pivot.x, flipperRec.y - pivot.y };
	corners[2] = { flipperRec.x - pivot.x, flipperRec.y + flipperRec.height - pivot.y };
	corners[3] = { flipperRec.x + flipperRec.width - pivot.x , flipperRec.y + flipperRec.height - pivot.y };

	//Bounding box coordinates
	float minX = FLT_MAX, minY = FLT_MAX, maxX = -FLT_MAX, maxY = -FLT_MAX;


	//update bounding box limits
	for (size_t i = 0; i < 4; i++)
	{
		//rotate and translate back
		float xNew = corners[i].x * c - corners[i].y * s + pivot.x;
		float yNew = corners[i].x * s + corners[i].y * c + pivot.y;

		if (xNew < minX) minX = xNew;
		if (yNew < minY) minY = yNew;
		if (xNew > maxX) maxX = xNew;
		if (yNew > maxY) maxY = yNew;
	}

	return { minX, minY, maxX - minX, maxY - minY };

}
