#include "Bullet.h"

#include "Asteroids.h"

void Bullet::OnCollision(GameObject& other){
	if (other.id != (char)Object::player)
		Master::DeleteObject(this);
}

void Bullet::update(float deltaTime){
	transform.Position += Direction * (speed * deltaTime);
	lifeSpan -= deltaTime;
	if(lifeSpan <= 0.0f){
		isActive = false;
		Master::DeleteObject(this);
	}
}

void Bullet::draw(aie::Renderer2D& render) {
	render.DrawSpriteTransformed3x3(texture, transform.GetGlobalTransform());
}

Bullet::Bullet() : GameObject({new CircleCollider(*this, Vector2(), 3.0f)}) {
	id = (char)Object::bullet;
	texture = new aie::Texture("./textures/bullet.png");

	CircleCollider* c = GetComponent<CircleCollider>();
	if(c)
		c->layerMask = Layer::default;
}


Bullet::~Bullet(){
	delete texture;
}
