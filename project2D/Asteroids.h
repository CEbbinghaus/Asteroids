#pragma once

#include "Includes.h"
#include "Asteroid.h"

enum class Object{
	player,
	asteroid,
	bullet,
	count
};

class Asteroids : public Level {
	atyp::Array<Asteroid*> activeAsteroids;
	atyp::Array<Asteroid*> deadAsteroids;

public:

	void update(float);
	void draw(aie::Renderer2D&);

	Asteroids();
	~Asteroids();
};