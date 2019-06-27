#pragma once
#include "Game.h"
#include "Renderer2D.h"
#include "atyp_Array.h"
#include "Level.h"
#include "Input.h"
#include "Application.h"


class Manager{
public:
	Manager();
	virtual void update(float deltaTime) = 0;
	virtual void draw(aie::Renderer2D& renderer) = 0;
};



class Master : public aie::Game {
	static Level* level;
	static atyp::Array<Manager*> managers;

	aie::Renderer2D& camera;

	void Update(float deltaTime);
	void Draw();

	atyp::Array<GameObject*> tbDeleted;
public:
	static aie::Input* input;
	static aie::Application* application;
	static Master* instance;

	static void RegisterManager(Manager*);
	static void LoadLevel(Level*);

	static void CreateGame();
	static void RunGame();
	static void DestroyGame();

	static void DeleteObject(GameObject*);

	Master();
	~Master();
};

