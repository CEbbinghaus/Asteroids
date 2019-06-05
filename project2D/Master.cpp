#include "Master.h"

Master* Master::instance = new Master();

void Master::Update(float deltaTime){
	for(Manager* manager : managers) {
		manager->update(deltaTime);
	}
	if (root)
		root->tick(deltaTime);
}

void Master::Draw(){
	for (Manager* manager : managers) {
		manager->draw(camera);
	}
	if (root)
		root->draw(camera);
}

void Master::RegisterManager(Manager* m){
	managers.push(m);
}

void Master::LoadLevel(Level* level){
	root = level;
	Transform::root = &(root->transform);
}

Master::Master() : Game("test", 1, 1, false), camera(*(new aie::Renderer2D())){
	root = nullptr;
}


Master::~Master(){
	for(Manager* m : managers){
		delete m;
	}
}
