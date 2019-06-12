#include "Asteroid.h"

#include "Collider.h"

void Asteroid::update(float deltaTime){
	Collider* collider = (Collider*)components.first();
	collider->radius = radius;

	transform.Position += velocity;


}

void Asteroid::draw(aie::Renderer2D& renderer){
	if(!points.length)return;
	float radOffset = (M_PI * 2) / (float)points.length;
	float lastRadius = points[points.length - 1];
	for(auto[PRadius, Index] : points){
		float xPos =  transform.Position.x + radius * *PRadius * sinf(Index * radOffset);
		float yPos =  transform.Position.y + radius * *PRadius * cosf(Index * radOffset);
		float PxPos = transform.Position.x + radius * lastRadius * sinf(--Index * radOffset);
		float PyPos = transform.Position.y + radius * lastRadius * cosf(Index * radOffset);

		renderer.DrawLine(PxPos, PyPos, xPos, yPos);

		lastRadius = *PRadius;
	}
}

void Asteroid::OnCollision(GameObject& other){

}

Asteroid::Asteroid() : GameObject({new Collider(*this, Vector2(1.0f, 1.0f), 10)}){
	velocity = Vector2(Random.get<float>(), Random.get<float>());

	radius = Random.get<float>(20.0f, 50.0f);

	int amount = Random.get<int>(7, 10);

	for(int i = 0; i < amount; i++){
		points.push(Random.get<float>(0.3f, 1.0f));
	}
}


Asteroid::~Asteroid(){

}
