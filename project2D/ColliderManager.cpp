#include "ColliderManager.h"
#include "ColliderFunctions.h"
#include "Rigidbody.h"

const collideFunc ColliderManager::collisionFunctions[] = {CircleCircle, CircleBox, CircleLine,
											  CircleBox,    BoxBox,    BoxLine,
											  CircleLine,   BoxLine,   LineLine};

ColliderManager* ColliderManager::Instance = nullptr;

void ColliderManager::RegisterCollider(Collider* col){
	colliders.push(col);
}

void ColliderManager::RemoveCollider(Collider* col){
	colliders.remove(col);
}

void ColliderManager::update(float deltaTime){
	Array<std::tuple<GameObject*, GameObject*>> needUpdate;

	for(int i = 0; i < colliders.length; ++i){
		for(int j = i + 1; j < colliders.length; ++j){

			Collider* a = colliders[i];
			Collider* b = colliders[j];

			if(&a->getParent() == &b->getParent())continue;
			if(!(a->layerMask & b->layerMask))continue;

			Vector2 normal;
			if(Collide(a, b, normal)){
				GameObject& gma = a->getParent();
				GameObject& gmb = b->getParent();

				needUpdate.push({&gma, &gmb});
				// a->getParent().OnCollision(b->getParent());
				// b->getParent().OnCollision(a->getParent());

				gma.transform.Position -= normal / 2;
				gmb.transform.Position += normal / 2;

			}
		}
	}
	for(std::tuple<GameObject*, GameObject*>& tuple : needUpdate){
		GameObject* a = std::get<0>(tuple);
		GameObject* b = std::get<1>(tuple);

		a->OnCollision(*b);
		b->OnCollision(*a);
	}
}

void ColliderManager::draw(aie::Renderer2D& renderer){
	if(!debug)return;
	renderer.SetRenderColour(0.0f, 0.5f, 0.2f, 0.3f);
	for (Collider* c : colliders) {
		Vector2 finalPos = c->GetWorldPosition();
		if(c->GetColliderType() == ColliderType::circle)
			renderer.DrawCircle(finalPos.x, finalPos.y, ((CircleCollider*)c)->radius);
	}
	renderer.SetRenderColour(1.0f, 1.0f, 1.0f);
}

bool ColliderManager::Collide(Collider * a, Collider * b, Vector2& out){
	if(a == b)return false;
	char aType = (char)a->GetColliderType();
	char bType = (char)b->GetColliderType();

	if((char)aType == -1 || (char)bType == -1)
		throw "Cannot Use Undefined Type";

	int index = aType * (char)ColliderType::size + bType;
	collideFunc function = collisionFunctions[index];

	if(aType < bType)
		return function(out, a, b);
	else
		return function(out, b, a);
}

ColliderManager::ColliderManager(){
	if(Instance)throw "There is Already a Instance of the Collision Manager";
	Instance = this;
	debug = false;
}


ColliderManager::~ColliderManager(){
	printf("Destroying Collider Manager");
	Instance = nullptr;
}
