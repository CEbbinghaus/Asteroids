#pragma once
#include "Component.h"

class Rigidbody: public Component{
    static Symbol type;

  public:
    Vector2 velocity;
    float mass;

    static Symbol GetStaticType() {
        return type;
    }
    virtual Symbol GetType() {
        return type;
    }
    
    Rigidbody(GameObject& parent, Vector2 initialVelocity = Vector2::zero());
    ~Rigidbody();
};