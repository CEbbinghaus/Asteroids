#include "Timer.h"

Timer::Timer(float time){
	totalTime = time;
}

Timer::Timer(float time, std::function<void()> callback){
	totalTime = time;
	listener = callback;
}

void Timer::Update(float deltaTime){
	if(timeLeft >= 0){
		timeLeft -= deltaTime;
		if(timeLeft <= 0){
			hasRunOut = true;
			if(listener)listener();
		}
	}
}

void Timer::Reset(){
	hasRunOut = false;
	timeLeft = totalTime;
}