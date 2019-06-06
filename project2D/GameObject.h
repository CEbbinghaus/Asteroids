#pragma once
#include "atyp_Array.h"
#include "Renderer2D.h"
#include "Transform.h"
#include "Asteroids.h"
#include "Collider.h"

class GameObject{
	atyp::Array<Component*> components;

	void tick(float);
	void beforeUpdate(float);
	virtual void update(float dt);
	void afterUpdate(float);


	void render(aie::Renderer2D&);
	void beforeDraw(aie::Renderer2D&);
	virtual void draw(aie::Renderer2D& renderer);
	void afterDraw(aie::Renderer2D&);


	virtual void OnCollision(GameObject& other);
public:

	bool isActive;

	Transform& transform;
	GameObject();
	GameObject(atyp::Array<Component*>);


	virtual ~GameObject();
};

