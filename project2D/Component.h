#pragma once
#include "GameObject.h"

enum componentType{
	undefined,
	collider,
	count
};

class Component{

	GameObject& parent;

public:
	GameObject& getParent();

	Component(GameObject&);

	virtual ~Component() = default;
};