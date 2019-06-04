#pragma once
#include "atyp_Array.h"
#include "Renderer2D.h"
#include "Transform.h"
#include "Asteroids.h"
#include "Component.h"
#include "Collider.h"

class GameObject{

	void tick();
	void beforeUpdate(float dt);
	void afterUpdate(float dt);

	atyp::Array<Component*> components;

public:

	bool isActive;

	Transform& transform;
	GameObject();
	GameObject(atyp::Array<Component*>);

	
	virtual void update(float dt);
	virtual void OnCollision(GameObject& other);
	virtual void render(aie::Renderer2D& renderer);


	virtual ~GameObject();
};

