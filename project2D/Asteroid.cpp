#include "Asteroid.h"
#include "Asteroids.h"

#include "Collider.h"

void Asteroid::update(float deltaTime){
	Collider* collider = (Collider*)components.first();
	collider->radius = radius;

	transform.Position += velocity;


	if (transform.Position.x + radius < 0)transform.Position.x = Master::application->GetWindowWidth() + radius;
	if (transform.Position.x - radius > Master::application->GetWindowWidth())transform.Position.x = -radius;
	if (transform.Position.y + radius < 0)transform.Position.y = Master::application->GetWindowHeight() + radius;
	if (transform.Position.y - radius > Master::application->GetWindowHeight())transform.Position.y = -radius;

	transform.Rotation += 0.01f;
}

void Asteroid::draw(aie::Renderer2D& renderer){
	if(!points.length)return;
	float radOffset = (M_PI * 2) / (float)points.length;
	float lastRadius = points[points.length - 1];

	for(auto [PRadius, Index] : points){

		Vector3 prev = Vector3(radius * *PRadius * sinf(Index * radOffset), radius * *PRadius * cosf(Index * radOffset), 1.0f);
		--Index;
		Vector3 next = Vector3(radius * lastRadius * sinf(Index * radOffset), radius * lastRadius * cosf(Index * radOffset), 1.0f);

		prev = transform.globalTransform * prev;
		next = transform.globalTransform * next;
		renderer.DrawLine(prev.x, prev.y, next.x, next.y);
		//float xPos =  transform.globalTransform.Pos.x + radius * *PRadius * sinf(Index * radOffset);
		//float yPos =  transform.globalTransform.Pos.y + radius * *PRadius * cosf(Index * radOffset);
		//float PxPos = transform.globalTransform.Pos.x + radius * lastRadius * sinf(--Index * radOffset);
		//float PyPos = transform.globalTransform.Pos.y + radius * lastRadius * cosf(Index * radOffset);
		//renderer.DrawLine(PxPos, PyPos, xPos, yPos);

		lastRadius = *PRadius;
	}
}

void Asteroid::OnCollision(GameObject& other){
	if (other.id == (char)Object::bullet) {
		int amount = 0;
		switch (size)
		{
			case 3:
				amount = Random.get<int>(2, 4);
			break;

			case 2:
				amount = Random.get<int>(0, 2);
			break;
		}
		float RadianOffset = Random.get<float>(0, M_PI * 2);
		float RadianAmount = (M_PI * 2) / amount;
		for (int i = 0; i < amount; ++i) {
			float finalRotation = RadianOffset + RadianAmount * i;
			Vector2 direction = Vector2(sinf(finalRotation), cosf(finalRotation));
			Vector2 currentPosition = *(Vector2*)(&(transform.globalTransform.Pos));
			Asteroids::instance->activeAsteroids.push(new Asteroid(size - 1, direction, currentPosition + direction * Random.get<float>(radius / 2, radius)));
		}
		Asteroids::instance->score += (100 * size);

		Asteroids::instance->activeAsteroids.remove(this);
		Master::DeleteObject(this);
	}
}

Asteroid::Asteroid(int a_size, Vector2 dir, Vector2 pos) : GameObject({new Collider(*this, Vector2(1.0f, 1.0f), 10)}){
	size = a_size;
	float min = (float)size * 20.0f;
	id = (char)Object::asteroid;

	radius = Random.get<float>(min, min * 2);

	velocity = dir;

	transform.Position = pos;
	int minP = 3 *  size;
	int maxP = 4 * size;
	int amount = Random.get<int>(minP, maxP);
	for(int i = 0; i < amount; i++){
		points.push(Random.get<float>(0.3f, 1.0f));
	}
}


Asteroid::~Asteroid(){
	//Asteroids::instance->activeAsteroids.remove(this);
}
