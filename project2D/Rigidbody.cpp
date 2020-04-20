#include "Rigidbody.h"
#include "PhysicsManager.h"

Symbol Rigidbody::type = Symbol("Rigidbody");

Rigidbody::Rigidbody(GameObject& parent, Vector2 initialVelocity): Component(parent){
    if(PhysicsManager::Instance != nullptr)
        PhysicsManager::Instance->RegisterRigidBody(this);
    velocity = initialVelocity;
}

Rigidbody::~Rigidbody(){
    if(PhysicsManager::Instance != nullptr)
        PhysicsManager::Instance->RemoveRigidbody(this);
}