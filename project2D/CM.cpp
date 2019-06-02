#include "CM.h"

CM* CM::Instance = new CM();

void CM::RegisterCollider(Collider* col){
	colliders.push(col);
}

void CM::RemoveCollider(Collider* col){
	colliders.remove(col);
}

CM::CM(){
	if(Instance)throw "There is Already a Instance of the Collision Manager";
}


CM::~CM(){
}
