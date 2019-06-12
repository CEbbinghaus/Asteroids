#pragma once

#include "Includes.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void update(float deltaTime);
	void draw(aie::Renderer2D& renderer);
	void OnCollision(GameObject&);
private:
	aie::Texture* m_texture;

	float m_posX;
	float m_posY;
};

