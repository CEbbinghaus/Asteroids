#pragma once
#include "GameObject.h"
#include "Texture.h"

class Bullet : public GameObject
{
	aie::Texture* texture;

	float speed = 10.0f;
	float lifeSpan = 5.0f;

public:
	Vector2 Direction;
	
	void update(float);
	void draw(aie::Renderer2D&);

	Bullet();
	~Bullet();
};

