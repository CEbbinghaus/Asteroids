#include "Bullet.h"

#include "Asteroids.h"

void Bullet::OnCollision(GameObject& other){
	if (other.id != (char)Object::player)
		Master::DeleteObject(this);
}

void Bullet::update(float deltaTime){
	transform.Position += Direction * speed;
	lifeSpan -= deltaTime;
	if(lifeSpan <= 0.0f){
		isActive = false;
		Master::DeleteObject(this);
	}
}

void Bullet::draw(aie::Renderer2D& render) {
	render.DrawSpriteTransformed3x3(texture, transform.globalTransform);
}

Bullet::Bullet() : GameObject({new Collider(*this, Vector2(), 3.0f)}) {
	id = (char)Object::bullet;
	texture = new aie::Texture("./textures/bullet.png");
}


Bullet::~Bullet(){
	delete texture;
}
