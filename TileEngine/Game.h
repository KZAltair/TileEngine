#pragma once
#include "Graphics.h"
#include "Timer.h"
#include "Tilemap.h"

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
	Window& wnd;
	Graphics gfx;
	Timer ft;
	/********************************/
	/*  User Variables              */
	/********************************/
	TileMap map;
	float x;
	float y;
	float PosX;
	float PosY;
	bool SleepingIsGranular;
};
