#pragma once
#include <atyp_Vector2.h>
#include "GameObject.h"
#include "Component.h"

enum class ColliderType: char{
	circle,
	square,
	line,
	size
};


enum class Layers: uint{
	default = 0b1,
	one = 1 << 1,
	two = 1 << 2,
	three = 1 << 3,
	four = 1 << 4,
	five = 1 << 5,
};

class Collider : public Component{
	static Symbol type;
  protected:
	Collider(GameObject&, Vector2, uint = (uint)Layers::default);

  public:
	uint layerMask;
	Vector2 position;


  	static Symbol GetStaticType(){
		return type;
	}

	virtual Symbol GetType(){
		return type;
	}

	Vector2 GetWorldPosition();

	virtual ColliderType GetColliderType();

	~Collider();
};

