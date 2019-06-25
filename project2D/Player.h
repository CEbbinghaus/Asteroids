#pragma once

#include "Includes.h"
#include "Turret.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float deltaTime);
	void draw(aie::Renderer2D& renderer);
	void OnCollision(GameObject&);
private:

	Turret turret;

	aie::Texture* m_texture;

	float m_posX;
	float m_posY;

	Vector2 velocity;
	float rotVel;

	float MoveSpeed = 25.0f;
	float RotationSpeed = 0.4f;
};

