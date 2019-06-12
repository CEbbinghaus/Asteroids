#pragma once
#include "Includes.h"


class Asteroid : public GameObject
{
	float radius;
	atyp::Array<float> points;

	Vector2 velocity;
public:

	void update(float);
	void draw(aie::Renderer2D&);

	void OnCollision(GameObject& other);

	Asteroid();
	~Asteroid();
};

