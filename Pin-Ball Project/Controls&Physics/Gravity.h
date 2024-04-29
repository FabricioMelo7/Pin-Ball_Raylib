#pragma once
#ifndef GRAVITY_H
#define GRAVITY_H

#include "raylib.h"
#include "../Entities/Ball.h"
#include "../Entities/Flippers.h"

Vector2 Euler(Vector2 a, float h);

const Vector2 gravity;

void SetForce(Ball& ball);
void ApplyEuler(Ball& ball);
void ApplyGravity(Ball& ball, float deltaTime);


#endif //GRAVITY_H

