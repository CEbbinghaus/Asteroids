#include "Transform.h"

Transform* Transform::root = nullptr;

void Transform::updateLocalTransform() {
	Matrix3 _pos;
	Matrix3 _scale;
	Matrix3 _rot;

	_pos.setPostion(Position.x, Position.y);
	_rot.setRotateZ(Rotation);
	_scale.setScale(Scale.x, Scale.y);
	
	localTransform = _pos * _rot * _scale;
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
