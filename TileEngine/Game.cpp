#include "Window.h"
#include "Game.h"

Game::Game(Window& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	map(0.0f, 0.0f, 50.0f)
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
	map.Draw(gfx);
	
}