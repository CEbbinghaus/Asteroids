#include "Includes.h"
#include "Collider.h"
#include "ColliderManager.h"

Symbol CircleCollider::type = Symbol("Collider.Circle");
Symbol BoxCollider::type = Symbol("Collider.Box");
Symbol LineCollider::type = Symbol("Collider.Line");
Symbol Collider::type = Symbol("Collider.Base");

Vector2 Collider::GetWorldPosition()
{
	/*Vector3 m = { position.x, position.y, 1};
	m = (Matrix3)getParent().transform * m;*/
	return Vector2(getParent().transform.globalTransform.Pos.x + position.x, getParent().transform.globalTransform.Pos.y + position.y);
}

ColliderType Collider::GetColliderType(){
	return (ColliderType)-1;
}

Collider::Collider(GameObject& parent, Vector2 pos, uint layer) : Component(parent), layerMask(layer){
	position = pos;
	ColliderManager::Instance->RegisterCollider(this);
}

Collider::~Collider(){
	if(ColliderManager::Instance)
		ColliderManager::Instance->RemoveCollider(this);
}
