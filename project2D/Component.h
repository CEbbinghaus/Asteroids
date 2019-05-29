#pragma once
#include "GameObject.h"


class Component{
	GameObject& parent;

public:
	GameObject& getParent();

	Component(GameObject&);
	~Component() = default;
};

