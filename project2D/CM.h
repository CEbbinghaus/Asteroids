#pragma once
#include "Collider.h"
#include "atyp_Array.h"

class CM{
	atyp::Array<Collider*> colliders;
public:
	static CM* Instance;

	void RegisterCollider(Collider*);
	void RemoveCollider(Collider*);
	CM();
	~CM();
};

