#include "Transform.h"



void Transform::updateLocalTransform() {
	localTransform = Matrix3();
	Vector3 Pos = { Position.x, Position.y, 1.0f };
	localTransform.setRotateZ(Rotation);
	localTransform[0] += Vector3(Scale.x, Scale.x, 0);
	localTransform[1] += Vector3(Scale.y, Scale.y, 0);
	localTransform[2] = Pos;
}

void Transform::updateGlobalTransform(){
	updateLocalTransform();
	Parent->updateGlobalTransform();
	globalTransform = (*Parent) * localTransform;
}

void Transform::SetParent(Transform* p){
	Parent = p;
}

Transform::Transform(GameObject& g) : gameObject(g){
	Position = Vector2(0.0f, 0.0f);
	Scale = Vector2(1.0f, 1.0f);
	Rotation = 0.0f;
}

Transform::Transform(GameObject& g, Vector2 pos, Vector2 size, float rot) : gameObject(g) {
	Position = pos;
	Scale = size;
	Rotation = rot;
}

Transform::Transform(GameObject& g, Matrix3 origin) : gameObject(g){
	Position = Vector2(0.0f, 0.0f);
	Scale = Vector2(1.0f, 1.0f);
	Rotation = 0.0f;
	globalTransform = origin;
}


Transform::~Transform(){
}

Transform Transform::operator*(Transform & other)
{
	return Transform(other.gameObject, globalTransform * other.localTransform);
}

Matrix3 Transform::operator*(Matrix3 & other)
{
	return Matrix3(globalTransform * other);
}

Transform::operator Matrix3(){
	return globalTransform;
}

Matrix3 operator*(Matrix3 & lhs, Transform & rhs)
{
	return Matrix3(lhs * *((Matrix3*)(&rhs)));
}
