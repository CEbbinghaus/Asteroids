#pragma once
#include "GameObject.h"
#include "Texture.h"

class Bullet : public GameObject
{
	aie::Texture* texture;

	float speed = 1000.0f;
	float lifeSpan = 5.0f;

public:
	Vector2 Direction;
	
	void OnCollision(GameObject&);

	void update(float);
	void draw(aie::Renderer2D&);

	Bullet();
	~Bullet();
};

