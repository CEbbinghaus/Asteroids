#include "GameObject.h"



void GameObject::tick(){
	float deltaTime = Game2D::deltaTime;
	beforeUpdate(deltaTime);
	update(deltaTime);
	afterUpdate(deltaTime);
}

void GameObject::beforeUpdate(float dt){
	transform.updateGlobalTransform();
}

void GameObject::afterUpdate(float dt){
	for(Transform* trf : transform.children) {
		trf->gameObject.tick();
	}
}

GameObject::GameObject() : transform(*(new Transform(*this))){
	isActive = true;
	GM::Instance->
}

GameObject::GameObject(atyp::Array<Component*> a_components) : transform(*(new Transform(*this))) {
	components = a_components;
	isActive = true;
}

void GameObject::update(float dt){}

void GameObject::OnCollision(GameObject& other){
}

void GameObject::render(aie::Renderer2D& renderer)
{
}


GameObject::~GameObject(){
	delete& transform;
}
