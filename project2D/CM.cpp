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
	renderer.SetRenderColour(0.0f, 0.5f, 0.2f, 0.3f);
	for (Collider* c : colliders) {
		Vector2 finalPos = c->GetWorldPosition();
		if(c->DebugRender)
			renderer.DrawCircle(finalPos.x, finalPos.y, c->radius);
	}
	renderer.SetRenderColour(1.0f, 1.0f, 1.0f);
}

bool CM::Collide(Collider * a, Collider * b){
	if(a == b)return false;
	float distance = (b->GetWorldPosition() - a->GetWorldPosition()).magnitude();
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
