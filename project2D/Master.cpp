#include "Master.h"

Master* Master::instance = nullptr;

Level* Master::level = nullptr;
atyp::Array<Manager*> Master::managers = {};


void Master::Update(float deltaTime){
	for(Manager* manager : managers) {
		manager->update(deltaTime);
	}

	if (level)
		level->tick(deltaTime);
}

void Master::Draw(){
	for (Manager* manager : managers) {
		manager->draw(camera);
	}
	if (level)
		level->draw(camera);
}

void Master::RegisterManager(Manager* m){
	managers.push(m);
}

void Master::LoadLevel(Level* a_level){
	level = a_level;
	Transform::root = &(level->transform);
}

Master::Master() : Game("test", 1, 1, false), camera(*(new aie::Renderer2D())){
	level = nullptr;
}


Master::~Master(){
	delete& camera;
	for(Manager* m : managers){
		delete m;
	}
}

Manager::Manager(){
	Master::RegisterManager(this);
}
