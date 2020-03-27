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
	//Update of the monitor 60Hz
	//Game update at software rendering is 30
	int numUpdateCalls = 0;
	float elapsedTime = ft.Mark();

	gfx.BeginFrame();
	while (elapsedTime > 0.0f)
	{
		//Updates are done by no more than 2,5 ms
		const float dt = std::min(0.00125f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
		numUpdateCalls++;
	}
	ComposeFrame();
	gfx.EndFrame();

	//Enable for debugging purpose to view framerate
	/*
	OutputDebugStringA(std::to_string(numUpdateCalls).c_str());
	OutputDebugStringA("\n");
	*/
}

void Game::UpdateModel(float dt)
{
	//Do update logic here
	
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
	x *= 300.0f;
	y *= 300.0f;
	PosX += x * dt;
	PosY += y * dt;

}

void Game::ComposeFrame()
{
	//Do the drawing stuff here
	map.Draw(gfx);
	gfx.DrawRectangle(PosX, PosY, 50.0f, 50.0f, Color(1.0f, 1.0f, 0.0f));
	
}