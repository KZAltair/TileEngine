#pragma once
#include "Graphics.h"
#include "Timer.h"
#include "Tilemap.h"
#include "Character.h"

class Game
{
public:
	Game(class Window& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel(float dt);
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	/********************************/
	/*  System Variables              */
	/********************************/
	Window& wnd;
	Graphics gfx;
	Timer ft;
	bool SleepingIsGranular;
	/********************************/
	/*  User Variables              */
	/********************************/
	TileMap map;
	Character p;


};
