#include "CM.h"

CM* CM::Instance = new CM();

void CM::RegisterCollider(Collider* col){
	colliders.push(col);
}

void CM::RemoveCollider(Collider* col){
	colliders.remove(col);
}

void CM::update(float deltaTime){

}

void CM::draw(aie::Renderer2D& renderer){

}

CM::CM(){
	if(Instance)throw "There is Already a Instance of the Collision Manager";
}


CM::~CM(){
}
