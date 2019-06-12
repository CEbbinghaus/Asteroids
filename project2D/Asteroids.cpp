#pragma once

#include "Asteroids.h"

void Asteroids::update(float deltaTime){
	//Quit the Game if the ESC key is Pressed
	if(Master::input->WasKeyPressed(aie::INPUT_KEY_ESCAPE))
		Master::application->Quit();

}

void Asteroids::draw(aie::Renderer2D& renderer){
	//renderer.SetRenderColour(1.0f, 1.0f, 1.0f);
	//renderer.DrawBox(0, 0, Master::application->GetWindowWidth(), Master::application->GetWindowHeight());
}

Asteroids::Asteroids(){
	//loads the Level Immediately so 
	Master::instance->LoadLevel(this);

	system("cls");
	Asteroid* test[10];
	atyp::Array<Asteroid*> testList;

	for(int i = 0; i < 10; ++i){
		test[i] = new Asteroid();
		test[i]->transform.SetParent(this);
	}

	if(activeAsteroids.length < 10){
		for(int i = 0; i < 10; i++){
			activeAsteroids.push(test[i]);
			//activeAsteroids[i]->transform.Position = Vector2(0.0f, Random.get<float>(0.0f, 200.0f));
			activeAsteroids[i]->transform.SetParent(this);
			activeAsteroids[i]->transform.setPostion(50, 50);
		}
	}
}

Asteroids::~Asteroids(){
}
