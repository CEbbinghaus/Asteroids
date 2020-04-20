#pragma once
#include "Collider.h"
#include "Master.h"
#include "atyp_Array.h"

using collideFunc = bool (*)(Vector2&, Collider*, Collider*);

class ColliderManager : public Manager{
	Array<Collider*> colliders;
public:
	const static collideFunc collisionFunctions[];

	static ColliderManager* Instance;

	bool debug;

	void RegisterCollider(Collider*);
	void RemoveCollider(Collider*);

	void update(float);
	void draw(aie::Renderer2D&);

	bool Collide(Collider*, Collider*, Vector2&);

	ColliderManager();
	virtual ~ColliderManager() override;
};

