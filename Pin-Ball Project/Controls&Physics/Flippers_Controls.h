#pragma once
#ifndef FLIPPERS_CONTROLS_H
#define FLIPPERS_CONTROLS_H

#include "../Entities/Flippers.h"
#include <vector>

class Flippers_Controls
{
public:
	Flippers_Controls();

	void PlayerInput( std::vector<Flippers*> flippers, float deltaTime);

private:
	void HandleLeftInput(Flippers* flipper, float deltaTime);
	void HandleRightInput(Flippers* flipper, float deltaTime);

	void UpdateFlipper(Flippers* flipper, float deltaTime);

	void Update(Flippers* flipper, float deltaTime);

	void ApplyLeftFlipperForce( Flippers* flipper);
	void ApplyRightFlipperForce(Flippers* flipper);

	void ResetFlipperValues(Flippers* flipper);

};

#endif // FLIPPERS_CONTROLS_H

