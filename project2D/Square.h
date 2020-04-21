#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "BoxCollider.h"

class Square : public GameObject{
  public:
    Square(): GameObject({new BoxCollider(*this, Vector2::zero(), 100, 100), new Rigidbody(*this)}){
        GetComponent<BoxCollider>()->layerMask = Layer::default | Layer::one;
        GetComponent<Rigidbody>()->useGravity = false;
    }

    void update(float deltaTime) override{
        if (transform.Position.x < 100)transform.Position.x = 100;
        if (transform.Position.x > Master::application->GetWindowWidth() - 100)transform.Position.x = Master::application->GetWindowWidth() - 100;
        if (transform.Position.y < 100)transform.Position.y = 100;
        if (transform.Position.y > Master::application->GetWindowHeight() - 100)transform.Position.y = Master::application->GetWindowHeight() - 100;
    }
};