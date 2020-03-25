#pragma once
#include "WinLib.h"
#include "Colors.h"
#include <vector>
#include "Utility.h"

class Graphics
{
public:
	Graphics(class HWNDKey& key);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	void BeginFrame(); //Does the loading of memory
	void EndFrame();
	void UpdateWindow();
	void MakeDIBSection();
	void PutPixel(int x, int y, Color c);
	void DrawRectangle(float MinX, float MinY, float MaxX, float MaxY, Color c);
	void DrawBackground(Color c);
	~Graphics();
private:
	BITMAPINFO bmpStruct = {0};
	std::vector<Color> memory;
	HDC DeviceContext;
	HWND hwnd;
public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};
