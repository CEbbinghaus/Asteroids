#pragma once
#include <Vector2.h>
#include "GameObject.h"
#include "Component.h"

class Collider : public Component{
	Vector2 position;
	float radius;

public:
	friend CM;
	Collider(GameObject&, Vector2, float);
	~Collider();
};

