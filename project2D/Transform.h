#pragma once
#include <memory>
#include "atyp_Array.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Matrix3.h"

class GameObject;

class Transform : public Matrix3{
	Matrix3 localTransform;
	Matrix3 globalTransform;

	void updateLocalTransform();
	void updateGlobalTransform();

public:
	GameObject& gameObject;

	atyp::Array<GameObject*> children;

	Transform* Parent;
	void SetParent(Transform*);

	Vector2 Position;
	Vector2 Scale;
	float Rotation;
	
	Transform(GameObject&);
	Transform(GameObject&, Vector2, Vector2, float);
	Transform(GameObject&, Matrix3);
	~Transform();

	Transform operator *(Transform& other);
	Matrix3 operator *(Matrix3& other);
	operator Matrix3();
};

Matrix3 operator * (Matrix3& lhs, Transform& rhs);