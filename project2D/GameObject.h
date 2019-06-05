#pragma once
#include "atyp_Array.h"
#include "Renderer2D.h"
#include "Transform.h"
#include "Asteroids.h"
#include "Component.h"
#include "Collider.h"

class GameObject{

	void tick(float);
	void beforeUpdate(float);
	void afterUpdate(float);

	atyp::Array<Component*> components;

	friend Master;
public:

	bool isActive;

	Transform& transform;
	GameObject();
	GameObject(atyp::Array<Component*>);

	
	virtual void update(float dt);
	virtual void OnCollision(GameObject& other);
	virtual void draw(aie::Renderer2D& renderer);


	virtual ~GameObject();
};

