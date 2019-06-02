#include "GM.h"

GM* GM::Instance = new GM();
		if (!object->transform.Parent){
			//object->tick();
		}
	}
}

void GM::render(aie::Renderer2D&){

}

void GM::RegisterGameObject(GameObject* gm){
	objects.push(gm);
}

void GM::RemoveGameObject(GameObject* gm){
	objects.remove(gm);
}

GM::GM(){
	if(Instance)throw "There is more than one instance of the Game";
}

GM::~GM(){}

void GM::tick(){
	for (GameObject* object : objects) {
