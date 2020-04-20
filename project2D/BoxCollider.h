#pragma once
#include "Collider.h"

#ifndef BoxCollider_Init
#define BoxCollider_Init

class BoxCollider : public Collider {
    static Symbol type;

   public:
    static Symbol GetStaticType() {
        return type;
    }

    virtual Symbol GetType() {
        return type;
    }

    BoxCollider(GameObject& parent, Vector2 position, float width, float height) : Collider(parent, position) {
        this->width = width;
        this->height = height;
    }

    float width;
    float height;

    ColliderType GetColliderType() override {
        return ColliderType::square;
    }
};

#endif