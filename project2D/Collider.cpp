#include "Collider.h"
#include "CM.h"

Collider::Collider(GameObject& parent, Vector2 pos, float rot) : Component(parent){
	CM::Instance->RegisterCollider(this);
}

Collider::~Collider(){
	CM::Instance->RemoveCollider(this);
}
