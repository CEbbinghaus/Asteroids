#pragma once
#include <Vector2.h>
#include "GameObject.h"
#include "Component.h"

class Collider : public Component{
public:

	Vector2 position;
	float radius;
	
	Vector2 GetWorldPosition();

	Collider(GameObject&, Vector2, float);
	~Collider();
};

