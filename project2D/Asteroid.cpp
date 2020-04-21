#include "Asteroid.h"
#include "Asteroids.h"

void Asteroid::update(float deltaTime){
	//transform.Position += velocity * (speed * deltaTime);


	if (transform.Position.x < 0)transform.Position.x = Master::application->GetWindowWidth();
	if (transform.Position.x > Master::application->GetWindowWidth())transform.Position.x = 0;
	if (transform.Position.y < 0)transform.Position.y = Master::application->GetWindowHeight();
	if (transform.Position.y > Master::application->GetWindowHeight())transform.Position.y = 0;
		
		
		/*if (transform.Position.x + radius < 0)transform.Position.x = Master::application->GetWindowWidth() + radius;
		if (transform.Position.x - radius > Master::application->GetWindowWidth())transform.Position.x = -radius;
		if (transform.Position.y + radius < 0)transform.Position.y = Master::application->GetWindowHeight() + radius;
		if (transform.Position.y - radius > Master::application->GetWindowHeight())transform.Position.y = -radius;
	*/
	transform.Rotation += rotationVelocity * deltaTime;
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
		switch (size){
			case 3:
				amount = Random.get<int>(2, 5);
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
			
			Asteroid* a = new Asteroid(size - 1, direction, currentPosition + direction * Random.get<float>(radius / 2, radius));
			Asteroids::instance->activeAsteroids.push(a);
		}
		Asteroids::instance->score += (100 * size);

		Asteroids::instance->activeAsteroids.remove(this);
		Master::DeleteObject(this);
	}
}

Asteroid::Asteroid(int a_size, Vector2 dir, Vector2 pos) : GameObject({new CircleCollider(*this, Vector2(1.0f, 1.0f), 10), new Rigidbody(*this, dir)}){
	rotationVelocity = Random.get<float>(0.0f, 0.3f);
	id = (char)Object::asteroid;
	
	CircleCollider* c = GetComponent<CircleCollider>();
	if(c)
		c->layerMask = Layer::default | Layer::one;

	size = a_size;
	speed = ((4 - size) * Asteroids::instance->level + 1) * 20;
	GetComponent<Rigidbody>()->velocity = speed * dir;

	float min = (float)size * 40.0f;


	GetComponent<CircleCollider>()->radius = radius = Random.get<float>(min, min * 1.3);
	// velocity = dir;

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
