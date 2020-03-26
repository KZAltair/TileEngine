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
	const float dt = ft.Mark();
	x = 0.0f;
	y = 0.0f;
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x = -1.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x = 1.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y = -1.0f;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y = 1.0f;
	}
	x *= 50.0f;
	y *= 50.0f;
	PosX += x * dt;
	PosY += y * dt;

}

void Game::ComposeFrame()
{
	//Do the drawing stuff here
	map.Draw(gfx);
	gfx.DrawRectangle(PosX, PosY, 50.0f, 50.0f, Color(1.0f, 1.0f, 0.0f));
	
}