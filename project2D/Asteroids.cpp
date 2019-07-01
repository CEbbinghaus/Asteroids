#pragma once

#include "Asteroids.h"
#include "Font.h"

Asteroids* Asteroids::instance = nullptr;

void Asteroids::update(float deltaTime){
	timeout.Update(deltaTime);

	if(Master::input->WasKeyPressed(aie::INPUT_KEY_ESCAPE))
		Master::application->Quit();

	if(activeAsteroids.isEmpty() && !hasSpawned){
		hasSpawned = true;
		timeout.Reset();
	}
	//transform.Rotation += 0.01f;
}

void Asteroids::draw(aie::Renderer2D& renderer){
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", Master::application->GetFPS());
	renderer.DrawText(font32, fps, 0, 720 - 32);

	sprintf_s(fps, 32, "Score: %i", score);
	renderer.DrawText(font32, fps, 0, 300);

	if(hasSpawned){
		sprintf_s(fps, 32, "%i", level);
		renderer.DrawText(font200, fps, Master::application->GetWindowWidth() / 2 - 75, Master::application->GetWindowHeight() / 2);
	}
}

void Asteroids::SpawnAsteroids(int amount){
	if(activeAsteroids.isEmpty()){
		for(int i = 0; i < amount; i++){
			Vector2 position = getRandomScreenPos();
			while((player.transform.Position - position).magnitude() < 200){
				position = getRandomScreenPos();
			}
			Asteroid* asteroid = new Asteroid(3, getRandomDirection(), position);
			activeAsteroids.push(asteroid);
			activeAsteroids[i]->transform.SetParent(this);
		}
	}
}

void Asteroids::UpdateLevel(){
	++level;
	SpawnAsteroids(level * 2 + 5);
	hasSpawned = false;
}

Asteroids::Asteroids() : timeout(2, std::bind(&Asteroids::UpdateLevel, this)){
	hasSpawned = false;
	instance = this;
	score = 0;
	level = 0;
	font32 = new aie::Font("./font/consolas.ttf", 32);
	font200 = new aie::Font("./font/consolas.ttf", 200);
	
	Master::instance->LoadLevel(this);
}

Asteroids::~Asteroids(){
	delete font32;
	delete font200;
	instance = nullptr;
}
