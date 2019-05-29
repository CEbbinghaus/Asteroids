#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include "Matrix3.h"

class Transform{
	Matrix3 localTransform;
	Matrix3 GlobalTransform;

public:
	Vector2 Position;
	float Rotation;
	
	Transform();
	~Transform();

	Matrix3 operator *(Transform& other);
	Matrix3 operator *(Matrix3& other);
};

