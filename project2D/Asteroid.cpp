#include "Asteroid.h"

#include "Collider.h"

Asteroid::Asteroid() : GameObject({new Collider(*this, Vector2(1.0f, 1.0f), 10)}){
}


Asteroid::~Asteroid()
{
}
