#pragma once
#include "atyp_Array.h"
#include "GameObject.h"

class GM{
	atyp::Array<GameObject*> objects;
public:
	static GM* Instance;
	GM();
	~GM();
};

