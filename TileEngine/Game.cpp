#include "Window.h"
#include "Game.h"
#pragma comment( lib, "winmm.lib" )

Game::Game(Window& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	map(0.0f, 0.0f, 50.0f),
	p(80.0f, 100.0f, map)
{
	//Windows scheduler function for waking up thread
	SleepingIsGranular = (timeBeginPeriod(1) == TIMERR_NOERROR);
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

		elapsedTime -= dt;
		numUpdateCalls++;
		if (SleepingIsGranular)
		{
			Sleep(DWORD(1 / 30 - dt));
			UpdateModel(dt);
		}
		
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
	p.Update(dt, wnd.kbd);

}

void Game::ComposeFrame()
{
	//Do the drawing stuff here
	map.Draw(gfx);
	p.Draw(gfx);
	
}