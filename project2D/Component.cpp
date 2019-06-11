#include "Component.h"



GameObject& Component::getParent(){
	return parent;
}

Component::Component(GameObject& p) : parent(p){}
