#pragma once
#include "GameObject.h"
class Level : public GameObject{
	friend Master;
public:
	Level();
	~Level();
};

