#pragma once

#include "Asteroids.h"

Asteroids::Asteroids(){
	Master::instance->LoadLevel(this);
}

Asteroids::~Asteroids(){
}
