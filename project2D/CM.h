#pragma once
#include "Collider.h"
#include "Master.h"
#include "atyp_Array.h"

class CM : public Manager{
	atyp::Array<Collider*> colliders;
public:
	static CM* Instance;

	void RegisterCollider(Collider*);
	void RemoveCollider(Collider*);

	void update(float);
	void draw(aie::Renderer2D&);

	bool Collide(Collider*, Collider*);

	CM();
	~CM();
};

