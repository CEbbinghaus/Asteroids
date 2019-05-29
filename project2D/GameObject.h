#pragma once
#include "atyp_Array.h"
#include "Renderer2D.h"
#include "Transform.h"

class GameObject{
	
	void tick();
	void beforeUpdate();
	void afterUpdate();

public:
	Transform& transform;
	GameObject();

	
	virtual void update(float dt);
	virtual void OnCollision(GameObject& other);
	virtual void render(aie::Renderer2D& renderer);


	virtual ~GameObject();
};

