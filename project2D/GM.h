#pragma once
#include "atyp_Array.h"
#include "GameObject.h"
#include "Renderer2D.h"

class GM{
	atyp::Array<GameObject*> objects;
public:
	static GM* Instance;

	void tick();

	void render(aie::Renderer2D&);

	void RegisterGameObject(GameObject*);
	void RemoveGameObject(GameObject*);

	GM();
	~GM();
};

