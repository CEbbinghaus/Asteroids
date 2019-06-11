#pragma once
#include "GameObject.h"
#include "atyp_Array.h"
class Asteroid : public GameObject
{
	atyp::Array<Asteroid*> Asteroids;
public:
	Asteroid();
	~Asteroid();
};

