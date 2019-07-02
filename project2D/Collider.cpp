#include "Collider.h"
#include "CM.h"

Vector2 Collider::GetWorldPosition()
{
	/*Vector3 m = { position.x, position.y, 1};
	m = (Matrix3)getParent().transform * m;*/
	return Vector2(getParent().transform.globalTransform.Pos.x + position.x, getParent().transform.globalTransform.Pos.y + position.y);
}

Collider::Collider(GameObject& parent, Vector2 pos, float rad) : Component(parent){
	position = pos;
	radius = rad;
	CM::Instance->RegisterCollider(this);
}

Collider::~Collider(){
	CM::Instance->RemoveCollider(this);
}
