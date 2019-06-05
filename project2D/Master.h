#pragma once
#include "Game.h"
#include "Renderer2D.h"
#include "atyp_Array.h"
#include "Level.h"

class Manager{
public:
	Manager(){
		Master::RegisterManager(this);
	};
	int index;
	virtual void update(float deltaTime) = 0;
	virtual void draw(aie::Renderer2D& renderer) = 0;
};

class Master : public aie::Game{
	static Level* root;
	static atyp::Array<Manager*> managers;

	virtual void Update(float deltaTime);
	virtual void Draw();

public:
	static void RegisterManager(Manager*);
	static void LoadLevel(Level*);
	Master();
	~Master();
};

