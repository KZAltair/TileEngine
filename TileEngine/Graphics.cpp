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
        bitmapMemory,
        &bmpStruct,
        DIB_RGB_COLORS,
        SRCCOPY
    );
}

void Graphics::MakeDIBSection()
{
    if (bitmapMemory)
    {
        VirtualFree(bitmapMemory, 0, MEM_RELEASE);
    }
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
    int BytesPerPixel = 4;
    int BitmapMemorySize = (ScreenWidth * ScreenHeight) * BytesPerPixel;

    bitmapMemory = VirtualAlloc(0, BitmapMemorySize, MEM_COMMIT, PAGE_READWRITE);
}

void Graphics::PutPixel(int x, int y, Color c)
{
    pSysBuffer = (Color*)bitmapMemory;

    if (pSysBuffer != nullptr)
    {
        pSysBuffer[y * Graphics::ScreenWidth + x] = c;
    }
}

Graphics::~Graphics()
{
    if (bitmapMemory)
    {
        VirtualFree(bitmapMemory, 0, MEM_RELEASE);
    }
    ReleaseDC(hwnd, DeviceContext);
}
