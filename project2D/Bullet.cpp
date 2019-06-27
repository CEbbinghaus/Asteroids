#include "Bullet.h"

#include "Asteroids.h"

void Bullet::update(float deltaTime){
	lifeSpan -= deltaTime;
	if(lifeSpan <= 0.0f){
		isActive = false;
		Master::DeleteObject(this);
	}
}

void Bullet::draw(aie::Renderer2D& render) {
	render.DrawSpriteTransformed3x3(texture, transform.globalTransform);
}

Bullet::Bullet(){
	id = (char)Object::bullet;
	texture = new aie::Texture("./textures/ship.png");
}


Bullet::~Bullet(){
	Asteroids::instance->bullets.remove(this);
	delete texture;
}
