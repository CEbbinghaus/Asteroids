#pragma once

#include "Asteroids.h"
#include "Font.h"
#include "ColliderManager.h"

Asteroids* Asteroids::instance = nullptr;

void Asteroids::update(float deltaTime){
	timeout.Update(deltaTime);

	if(Master::input->WasKeyPressed(aie::INPUT_KEY_ESCAPE))
		Master::application->Quit();

	if(Master::input->WasKeyPressed(aie::INPUT_KEY_F3))
		ColliderManager::Instance->debug = !ColliderManager::Instance->debug;

	if(Master::input->WasKeyPressed(aie::INPUT_KEY_F4))
		Master::application->SetVSync(Vsync = !Vsync);

	if(activeAsteroids.isEmpty() && timeout.hasRunOut){
		timeout.Reset();
	}
	//transform.Rotation += 0.01f;
}

void Asteroids::draw(aie::Renderer2D& renderer){
	char fps[32];
	sprintf_s(fps, 32, "%i", Master::application->GetFPS());
	renderer.DrawText(font32, fps, Master::application->GetWindowWidth() - 100, Master::application->GetWindowHeight() - 32);

	sprintf_s(fps, 32, "Score: %i", score);
	renderer.DrawText(font32, fps, 0, Master::application->GetWindowHeight() - 32);

	if(!timeout.hasRunOut){
		sprintf_s(fps, 32, "%i", level);
		renderer.DrawText(font200, fps, Master::application->GetWindowWidth() / 2 - 75, Master::application->GetWindowHeight() / 2);
	}

	float offset = ((float)player.lives / 2);
	for(int i = 0; i < player.lives; ++i){
		float x = Master::application->GetWindowWidth() / 2 - (offset * 50 + 10);
		float y = Master::application->GetWindowHeight() - 50;
		renderer.DrawSprite(playerTexture, x + i * 50 + 10 , y, 50, 50);
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
	SpawnAsteroids(level * 3 + 2);
	player.lives++;
}

Asteroids::Asteroids() : timeout(2, std::bind(&Asteroids::UpdateLevel, this)){
	instance = this;
	score = 0;
	level = 0;
	font32 = new aie::Font("./font/consolas.ttf", 32);
	font200 = new aie::Font("./font/consolas.ttf", 200);
	playerTexture = new aie::Texture("./textures/ship.png");

	Master::instance->LoadLevel(this);
}

Asteroids::~Asteroids(){
	delete font32;
	delete font200;
	instance = nullptr;
}
