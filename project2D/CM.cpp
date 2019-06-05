#include "CM.h"

CM* CM::Instance = new CM();

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

		}
	}
}

void CM::draw(aie::Renderer2D& renderer){

}

bool CM::Collide(Collider * a, Collider * b){
	//TODO: Make Collisions Happen
	return false;
}

CM::CM(){
	if(Instance)throw "There is Already a Instance of the Collision Manager";
}


CM::~CM(){
}
