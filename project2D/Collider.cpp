#include "Collider.h"
#include "CM.h"

Vector2 Collider::GetWorldPosition()
{
	Vector3 m = { position.x, position.y, 0 };
	m = (Matrix3)getParent().transform * m;
	return Vector2(m.x, m.y);
}

Collider::Collider(GameObject& parent, Vector2 pos, float rot) : Component(parent){
	CM::Instance->RegisterCollider(this);
}

Collider::~Collider(){
	CM::Instance->RemoveCollider(this);
}
