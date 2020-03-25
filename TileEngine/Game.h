#pragma once
#include "Graphics.h"
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
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	Window& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	TileMap map;
};
