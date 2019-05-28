#pragma once
class GameObject{

	void tick();
	void beforeUpdate();
	void afterUpdate();

public:
	GameObject();

	
	virtual void update(float dt);
	virtual ~GameObject();
};

