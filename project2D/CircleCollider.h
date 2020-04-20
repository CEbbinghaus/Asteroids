#pragma once
#include "Collider.h"

#ifndef CircleCollider_Init
#define CircleCollider_Init

class CircleCollider : public Collider{
  static Symbol type;

  public:

    static Symbol GetStaticType(){
      return type;
    }

    virtual Symbol GetType(){
      return type;
    }

    CircleCollider(GameObject& parent, Vector2 position, float radius): Collider(parent, position){
      this->radius = radius;
    }

    float radius;

    ColliderType GetColliderType() override{
        return ColliderType::circle;
    }
};

#endif