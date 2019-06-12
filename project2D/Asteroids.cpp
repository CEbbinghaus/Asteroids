#pragma once

#include "Asteroids.h"

void Asteroids::update(float deltaTime){
	if(Master::input->WasKeyPressed(aie::INPUT_KEY_ESCAPE))
		Master::application->Quit();

	//transform.Rotation += 0.01f;
}

void Asteroids::draw(aie::Renderer2D& renderer){
}

Asteroids::Asteroids(){
	Master::instance->LoadLevel(this);

	if(activeAsteroids.length < 10){
		for(int i = 0; i < 10; i++){
			activeAsteroids.push(new Asteroid());
			activeAsteroids[i]->transform.SetParent(this);
			activeAsteroids[i]->transform.setPostion(50, 50);
		}
	}
}

Asteroids::~Asteroids(){
	for (Asteroid* a : activeAsteroids) {
		delete a;
	}
}
