#include "CM.h"

CM* CM::Instance = nullptr;

void CM::RegisterCollider(Collider* col){
	colliders.push(col);
}

void CM::RemoveCollider(Collider* col){
	colliders.remove(col);
}

void CM::update(float deltaTime){
	for (Collider* c : colliders) {
		for (Collider* oc : colliders) {
			if(&c->getParent() == &oc->getParent())continue;
			Collide(c, oc);
		}
	}
}

void CM::draw(aie::Renderer2D& renderer){
	for (Collider* c : colliders) {
		if(c->DebugRender);
	}
}

bool CM::Collide(Collider * a, Collider * b){
	float distance = a->GetWorldPosition().dot(b->GetWorldPosition());
	if (distance < a->radius + b->radius){
		a->getParent().OnCollision(b->getParent());
		return true;
	}
	return false;
}

CM::CM(){
	if(Instance)throw "There is Already a Instance of the Collision Manager";
	Instance = this;
}


CM::~CM(){
	Instance = nullptr;
}
