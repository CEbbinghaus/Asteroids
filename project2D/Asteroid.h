#pragma once
#include "Includes.h"

static Vector2 getRandomDirection(){
	float rotation = Random.get<float>() * M_PI;
	return Vector2(sinf(rotation), cosf(rotation));
}

static Vector2 getRandomScreenPos(){
	return Vector2(Random.get<float>(0.0f, Master::application->GetWindowWidth()), Random.get<float>(0.0f, Master::application->GetWindowHeight()));
}


class Asteroid : public GameObject
{


	float radius;
	atyp::Array<float> points;

	Vector2 velocity;
public:

	int size;

	void update(float);
	void draw(aie::Renderer2D&);

	void OnCollision(GameObject& other);

	Asteroid(int = 3, Vector2 = getRandomDirection(), Vector2 = getRandomScreenPos());
	~Asteroid();
};

