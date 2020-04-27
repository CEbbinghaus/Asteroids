#pragma once
#include "GameObject.h"
#include "Rigidbody.h"
#include "CircleCollider.h"
#include "Master.h"

class Circle : public GameObject{
  public:
    CircleCollider* cCollider;
    Rigidbody* rb;

    float Radius = 50;

    Circle(float magnitude = 100): GameObject({new CircleCollider(*this, Vector2::zero(), 0), new Rigidbody(*this)}){
        Radius = magnitude / 2;

        cCollider = GetComponent<CircleCollider>();
        cCollider->layerMask = Layer::default | Layer::one;
        cCollider->radius = Radius;


        rb = GetComponent<Rigidbody>();
        rb->mass = magnitude;
        //rb->useGravity = false;
    }

    void update(float deltaTime) override{
        if (transform.Position.x < Radius / 2){
            rb->velocity *= Vector2(-1, 1);
            transform.Position.x = Radius / 2;
        }
        if (transform.Position.x > Master::application->GetWindowWidth() - Radius / 2){
            rb->velocity *= Vector2(-1, 1);
            transform.Position.x = Master::application->GetWindowWidth() - Radius / 2;
        }
        if (transform.Position.y < Radius / 2){
            rb->velocity *= Vector2(1, -1);
            transform.Position.y = Radius / 2;
        }
        if (transform.Position.y > Master::application->GetWindowHeight() - Radius / 2){
            rb->velocity *= Vector2(1, -1);
            transform.Position.y = Master::application->GetWindowHeight() - Radius / 2;
        }
    }

    void draw(aie::Renderer2D& renderer){
        renderer.DrawCircle(transform.Position.x, transform.Position.y, Radius);
    }
};