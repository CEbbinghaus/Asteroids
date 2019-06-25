#pragma once
#include "GameObject.h"
#include "Texture.h"
#include "Renderer2D.h"

class Turret :	public GameObject
{
	aie::Texture* texture;

	void shoot();
public:

	float rotationSpeed = 1.4f;

	void update(float);
	void draw(aie::Renderer2D&);

	Turret();
	~Turret();
};

