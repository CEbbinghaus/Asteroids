#pragma once

#include "Includes.h"
#include "Asteroid.h"
#include "Player.h"
#include "Bullet.h"
#include "Timer.h"

enum class Object{
	player,
	asteroid,
	bullet,
	count
};

class Asteroids : public Level {
public:
	static Asteroids* instance;

	Timer timeout;

	bool Vsync;

	Array<Asteroid*> activeAsteroids;
	Array<Bullet*> bullets;

	Player player;
	aie::Font* font32;
	aie::Font* font200;
	aie::Texture* playerTexture;

	unsigned char level;
	unsigned long long int score;

	void update(float);
	void draw(aie::Renderer2D&);
	void SpawnAsteroids(int amount);
	void UpdateLevel();

	Asteroids();
	~Asteroids();
};