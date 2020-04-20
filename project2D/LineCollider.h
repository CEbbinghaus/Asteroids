#pragma once
#include "Collider.h"

class LineCollider : public Collider {
    static Symbol type;

   public:
    float rotation;

    static Symbol GetStaticType() {
        return type;
    }
    virtual Symbol GetType() {
        return type;
    }

    LineCollider(GameObject& parent, Vector2 position, float rotation) : Collider(parent, position) {
        this->rotation = rotation;
    }

    ColliderType GetColliderType() override {
        return ColliderType::line;
    }
};