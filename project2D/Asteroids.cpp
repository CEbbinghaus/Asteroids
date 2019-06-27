#pragma once

#include "Asteroids.h"

Asteroids* Asteroids::instance = nullptr;

void Asteroids::update(float deltaTime){
	if(Master::input->WasKeyPressed(aie::INPUT_KEY_ESCAPE))
		Master::application->Quit();

	//transform.Rotation += 0.01f;
}

void Asteroids::draw(aie::Renderer2D& renderer){
}

Asteroids::Asteroids(){
	instance = this;
	Master::instance->LoadLevel(this);

	if(activeAsteroids.length < 10){
		for(int i = 0; i < 10; i++){
			activeAsteroids.push(new Asteroid());
			activeAsteroids[i]->transform.SetParent(this);
		}
	}
}

Asteroids::~Asteroids(){
	instance = nullptr;
}
