#pragma once

#include "Includes.h"
#include "Asteroid.h"
#include "Player.h"
#include "Bullet.h"

enum class Object{
	player,
	asteroid,
	bullet,
	count
};

class Asteroids : public Level {
public:
	static Asteroids* instance;

	atyp::Array<Asteroid*> activeAsteroids;
	atyp::Array<Bullet*> bullets;

	Player player;

	void update(float);
	void draw(aie::Renderer2D&);

	Asteroids();
	~Asteroids();
};