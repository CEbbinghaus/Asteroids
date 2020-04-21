#pragma once
#include "Component.h"

class Rigidbody: public Component{
    static Symbol type;

  public:
    Vector2 velocity;
    float mass;
    bool useGravity;

    static Symbol GetStaticType() {
        return type;
    }
    virtual Symbol GetType() {
        return type;
    }
    
    Rigidbody(GameObject& parent, Vector2 = Vector2::zero(), bool = true);
    ~Rigidbody();
};