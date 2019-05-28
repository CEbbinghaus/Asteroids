#include "GM.h"

GM* GM::Instance = new GM();

GM::GM(){
	if(Instance)throw "There is more than one instance of the Game";
}


GM::~GM(){
}
