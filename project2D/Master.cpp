#include "Master.h"



void Master::Update(float deltaTime){
}

void Master::Draw(){
}

void Master::RegisterManager(Manager* m){
	managers.push(m);
}

void Master::LoadLevel(Level* level){
	root = level;
	Transform::root = &(root->transform);
}

Master::Master(){
	root = nullptr;
}


Master::~Master(){
	for(Manager* m : managers){
		delete m;
	}
}
