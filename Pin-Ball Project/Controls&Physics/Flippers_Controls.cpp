#include "Flippers_Controls.h"

Flippers_Controls::Flippers_Controls(){}

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
}

void Flippers_Controls::ResetFlipperValues(Flippers* flipper)
{
	flipper->dr = { 0.0f, 0.0f };
	flipper->v = { 0.0f, 0.0f };
	flipper->dv = { 0.0f, 0.0f };	
}
