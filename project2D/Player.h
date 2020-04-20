#pragma once

#include "Includes.h"
#include "Turret.h"
#include "Timer.h"
#include "Rigidbody.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float deltaTime);
	void draw(aie::Renderer2D& renderer);
	void OnCollision(GameObject&);
	
	char lives;
private:

	Rigidbody* rb;

	Turret turret;

	Timer invunerability;

	aie::Texture* m_texture;

	float m_posX;
	float m_posY;

	Vector2 velocity;
	float rotVel;

	float MoveSpeed = 2000.0f;
	float RotationSpeed = 20.00f;
};

