#pragma once
#include <functional>

class Timer{
private:
	std::function<void()> listener;
public:
	float timeLeft = 0;
	float totalTime;
	bool hasRunOut = true;

	Timer(float time);
	Timer(float time, std::function<void()> callback);
	void Update(float deltaTime);
	void Reset();
};