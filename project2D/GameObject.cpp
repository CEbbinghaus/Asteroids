#include "GameObject.h"
#include "Component.h"


void GameObject::tick(float deltaTime){
	if(!isActive)return;
	beforeUpdate(deltaTime);
	update(deltaTime);
	afterUpdate(deltaTime);
}

void GameObject::beforeUpdate(float dt){
	transform.updateGlobalTransform();
}

void GameObject::afterUpdate(float dt){
	for(Transform* trf : transform.children) {
		trf->gameObject.tick(dt);
	}
}

GameObject::GameObject() : transform(*(new Transform(*this))){
	isActive = true;
}

GameObject::GameObject(atyp::Array<Component*> a_components) : transform(*(new Transform(*this))) {
	components = a_components;
	isActive = true;
}

void GameObject::update(float dt){}

void GameObject::OnCollision(GameObject& other){
}

void GameObject::render(aie::Renderer2D& renderer){
	beforeDraw(renderer);
	draw(renderer);
	afterDraw(renderer);
}

void GameObject::beforeDraw(aie::Renderer2D& renderer){
	
}

void GameObject::draw(aie::Renderer2D& renderer){}

void GameObject::afterDraw(aie::Renderer2D& renderer){
	for (Transform* trf : transform.children) {
		trf->gameObject.render(renderer);
	}
}


GameObject::~GameObject(){
	for (Component* c : components) {
		delete c;
	}
	delete& transform;
}
