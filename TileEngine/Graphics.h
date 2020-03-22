#pragma once
#include "WinLib.h"
#include "Colors.h"

class Graphics
{
public:
	Graphics(class HWNDKey& key);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	void BeginFrame();
	void EndFrame();
	void UpdateWindow();
	void MakeDIBSection();
	void PutPixel(int x, int y, Color c);
	~Graphics();
private:
	BITMAPINFO bmpStruct = {0};
	void* bitmapMemory = nullptr;
	Color* pSysBuffer = nullptr;
	HDC DeviceContext;
	HWND hwnd;
public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};
