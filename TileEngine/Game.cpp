#include "Window.h"
#include "Game.h"

Game::Game(Window& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//Do update logic here
}

void Game::ComposeFrame()
{
	//Do the drawing stuff here
	gfx.DrawBackground(Color(0, 0, 0));
	gfx.DrawRectangle(10.0f, 10.0f, 30.0f, 30.0f, Color(255, 255, 0));
	
}