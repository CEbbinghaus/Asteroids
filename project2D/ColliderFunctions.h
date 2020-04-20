#include <atyp_Vector2.h>
#include "CircleCollider.h"
#include "BoxCollider.h"
#include "LineCollider.h"


bool CircleCircle(Vector2& out, Collider* a, Collider* b){ //0
	CircleCollider& ca = *(CircleCollider*)a;
	CircleCollider& cb = *(CircleCollider*)b;

	Vector2 aPos = ca.GetWorldPosition();
	Vector2 bPos = cb.GetWorldPosition();

	float distance = (aPos - bPos).magnitude();

	if(distance < ca.radius + cb.radius){
		out = ((ca.radius + cb.radius) / distance) * (aPos - bPos).normalise();
		return true;
	}
	return false;
}
bool CircleBox(Vector2& out, Collider* a, Collider* b){ //1
	CircleCollider& ca = *(CircleCollider*)a;
	BoxCollider& sb = *(BoxCollider*)b;
	return false;
}
bool CircleLine(Vector2& out, Collider* a, Collider* b){ //2
	CircleCollider& ca = *(CircleCollider*)a;
	LineCollider& lb = *(LineCollider*)b;
	return false;
}
bool BoxBox(Vector2& out, Collider* a, Collider* b){ //3
	BoxCollider& sa = *(BoxCollider*)a;
	BoxCollider& sb = *(BoxCollider*)b;
	return false;

}
bool BoxLine(Vector2& out, Collider* a, Collider* b){ //4
	BoxCollider& sa = *(BoxCollider*)a;
	LineCollider& lb = *(LineCollider*)b;
	return false;
}
bool LineLine(Vector2& out, Collider* a, Collider* b){ //5
	out = Vector2::zero();
	return false;
}