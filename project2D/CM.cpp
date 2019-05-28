#include "CM.h"

CM* CM::Instance = new CM();

CM::CM(){
	if(Instance)throw "There is Already a Instance of the Collision Manager";
}


CM::~CM(){
}
