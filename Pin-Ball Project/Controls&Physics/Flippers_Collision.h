#pragma once

#ifndef FLIPPERS_COLLISION_H
#define FLIPPERS_COLLISION_H

#include<raylib.h>
#include "../Entities/Flippers.h"
#include "../Entities/Ball.h"

class Flippers_Collision
{
public:
	Flippers_Collision();

	Rectangle GetRotatedFlipperBoundingBox(Rectangle flipperRec, float angle, Vector2 pivot);
	

};

#endif // !FLIPPERS_COLLISION_H

