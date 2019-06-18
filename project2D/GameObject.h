#pragma once
#include "atyp_Array.h"
#include "Renderer2D.h"
#include "Transform.h"

class Component;

class GameObject{
	friend class Master;
	friend class CM;

	void tick(float);
	virtual void beforeUpdate(float);
	virtual void update(float dt);
	virtual void afterUpdate(float);


	void render(aie::Renderer2D&);
	void beforeDraw(aie::Renderer2D&);
	virtual void draw(aie::Renderer2D& renderer);
	void afterDraw(aie::Renderer2D&);

	virtual void OnCollision(GameObject& other);


protected:
	atyp::Array<Component*> components;

public:
	char id;
	bool isActive;

	Transform transform;

	GameObject();
	GameObject(atyp::Array<Component*>);


	virtual ~GameObject();
};

