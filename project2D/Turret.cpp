#include "Turret.h"
#include "Master.h"
#include "Bullet.h"
#include "Asteroids.h"

void Turret::shoot(){

	Bullet* b = new Bullet();
	b->transform.Position = Vector2(transform.globalTransform.Pos.x, transform.globalTransform.Pos.y);
	//Vector3 dir = transform.globalTransform.AxisY;
	//b->Direction = Vector2(dir.x, dir.y);

	//b->transform.SetParent(Asteroids::instance);
	//Asteroids::instance->bullets.push(b);
}

void Turret::update(float deltaTime){
	auto input = Master::input;
	if (input->IsKeyDown(aie::INPUT_KEY_Q)){
		transform.Rotation += rotationSpeed * deltaTime;
	}
	
	if (input->IsKeyDown(aie::INPUT_KEY_E)){
		transform.Rotation -= rotationSpeed * deltaTime;
	}

	if (input->IsKeyDown(aie::INPUT_KEY_SPACE)) {
		shoot();
	}
}

void Turret::draw(aie::Renderer2D& render){
	render.DrawSpriteTransformed3x3(texture, transform.globalTransform);
}

Turret::Turret(){
	texture = new aie::Texture("./textures/barrelBeige.png");
}


Turret::~Turret(){
	delete texture;
}
