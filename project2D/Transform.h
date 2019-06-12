#pragma once
#include <memory>
#include "atyp_Array.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Matrix3.h"

class GameObject;

class Transform : public Matrix3{
	friend GameObject;


	void updateLocalTransform();
	void updateGlobalTransform();

public:
	Matrix3 globalTransform;
	Matrix3 localTransform;


	static Transform* root;

	GameObject& gameObject;

	atyp::Array<Transform*> children;

	Transform* Parent;
	void TransferParent(Transform*);
	void SetParent(Transform*);
	void SetParent(GameObject*);
	void SetParent(std::nullptr_t);

	Vector2 Position;
	Vector2 Scale;
	float Rotation;
	
	Transform(GameObject&);
	Transform(GameObject&, Matrix3);
	Transform(GameObject&, Vector2, Vector2, float);
	~Transform();

	Transform operator *(Transform& other);
	Matrix3 operator *(Matrix3& other);

	operator Matrix3();
};

Matrix3 operator * (Matrix3& lhs, Transform& rhs);