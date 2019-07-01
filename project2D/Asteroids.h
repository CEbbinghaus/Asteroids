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

struct Timer{
private:
	std::function<void()> listener;
public:
	float timeLeft = 0;
	float totalTime;

	Timer(float time){
		totalTime = time;
	}
	Timer(float time, std::function<void()> callback){
		totalTime = time;
		listener = callback;
	}
	void Update(float deltaTime){
		if(timeLeft > 0){
			timeLeft -= deltaTime;
			if(timeLeft < 0){
				listener();
			}
		}
	}
	void Reset(){
		timeLeft = totalTime;
	}
};

class Asteroids : public Level {
public:
	static Asteroids* instance;

	bool hasSpawned;
	Timer timeout;

	atyp::Array<Asteroid*> activeAsteroids;
	atyp::Array<Bullet*> bullets;

	Player player;
	aie::Font* font32;
	aie::Font* font200;

	unsigned char level;
	unsigned long long int score;

	void update(float);
	void draw(aie::Renderer2D&);
	void SpawnAsteroids(int amount);
	void UpdateLevel();

	Asteroids();
	~Asteroids();
};