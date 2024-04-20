#include "Ball.h"

void ApplyTexture(Model& obj, Texture2D& tex)
{
	obj.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = tex;
}

MoonSphere::MoonSphere()
{
	 moon = LoadModel("Moon.obj");
	 tex = LoadTexture("MoonTexture.png");
	 ApplyTexture(moon, tex);
}

