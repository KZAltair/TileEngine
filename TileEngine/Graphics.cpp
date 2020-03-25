#include "Window.h"
#include "Graphics.h"
#include <assert.h>

Graphics::Graphics(HWNDKey& key)
{
    assert(key.hwnd != nullptr);
    hwnd = key.hwnd;
}

void Graphics::BeginFrame()
{
    MakeDIBSection();
}

void Graphics::EndFrame()
{
    UpdateWindow();
}

void Graphics::UpdateWindow()
{
    DeviceContext = GetDC(hwnd);
    StretchDIBits(
        DeviceContext, 0, 0, ScreenWidth, ScreenHeight, 0, 0, ScreenWidth, ScreenHeight,
        memory.data(),
        &bmpStruct,
        DIB_RGB_COLORS,
        SRCCOPY
    );
}

void Graphics::MakeDIBSection()
{
    /*if (bitmapMemory)
    {
        VirtualFree(bitmapMemory, 0, MEM_RELEASE);
    }
    */
    //Create struct ot define bitmap
    bmpStruct.bmiHeader.biSize = sizeof(bmpStruct.bmiHeader);
    bmpStruct.bmiHeader.biWidth = ScreenWidth;
    bmpStruct.bmiHeader.biHeight = -ScreenHeight;
    bmpStruct.bmiHeader.biPlanes = 1;
    bmpStruct.bmiHeader.biBitCount = 32;
    bmpStruct.bmiHeader.biCompression = BI_RGB;
    bmpStruct.bmiHeader.biSizeImage = 0;
    bmpStruct.bmiHeader.biXPelsPerMeter = 0;
    bmpStruct.bmiHeader.biYPelsPerMeter = 0;
    bmpStruct.bmiHeader.biClrUsed = 0;
    bmpStruct.bmiHeader.biClrImportant = 0;

    //filled int with RGB values memory chunk
    //int BytesPerPixel = 4; //Possibly we do not need it as we store Color already
    int BitmapMemorySize = (ScreenWidth * ScreenHeight);
    memory.resize(BitmapMemorySize);
}

void Graphics::PutPixel(int x, int y, Color c)
{
    assert(x > 0);
    assert(x < ScreenWidth);
    assert(y > 0);
    assert(y < ScreenHeight);
    memory[y * ScreenWidth + x] = c;
}

void Graphics::DrawRectangle(float xD, float yD, float width, float height, Color c)
{
    int MinX = RoundFloatToInt(xD);
    int MaxX = RoundFloatToInt(width) + xD;
    int MinY = RoundFloatToInt(yD);
    int MaxY = RoundFloatToInt(height) + yD;
    if (MinX < 0)
    {
        MinX = 0;
    }
    if (MaxX > ScreenWidth)
    {
        MaxX = ScreenWidth;
    }
    if (MinY < 0)
    {
        MinY = 0;
    }
    if (MaxY > ScreenHeight)
    {
        MaxY = ScreenHeight;
    }

    for (int y = MinY; y < MaxY; ++y)
    {
        for (int x = MinX; x < MaxX; ++x)
        {
            memory[y * ScreenWidth + x] = c;
        }
    }
}

void Graphics::DrawBackground(Color c)
{
    for (int y = 0; y < ScreenHeight; ++y)
    {
        for (int x = 0; x < ScreenWidth; ++x)
        {
            memory[y * ScreenWidth + x] = c;
        }
    }
}

Graphics::~Graphics()
{
    ReleaseDC(hwnd, DeviceContext);
}
