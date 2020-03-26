#pragma once
#include "WinLib.h"
#include "Exception.h"
#include "Graphics.h"
#include "Keyboard.h"

// for granting special access to hWnd only for Graphics constructor
class HWNDKey
{
	friend Graphics::Graphics(HWNDKey&);
public:
	HWNDKey(const HWNDKey&) = delete;
	HWNDKey& operator=(HWNDKey&) = delete;
protected:
	HWNDKey() = default;
protected:
	HWND hwnd = nullptr;
};

class Window : public HWNDKey
{

public:
	class Exception : public EngineException
	{
	public:
		using EngineException::EngineException;
		virtual std::wstring GetFullMessage() const override { return GetNote() + L"\nAt: " + GetLocation(); }
		virtual std::wstring GetExceptionType() const override { return L"Windows Exception"; }
	};

public:
	Window(HINSTANCE hInst);
	Window(const Window&) = delete; //No multiple windows allowed
	Window& operator=(const Window&) = delete; //No multiple windows allowed
	~Window();
	bool ProcessMessage();
	void ShowMessageBox(const std::wstring& title, const std::wstring& message, UINT type = MB_OK) const;
private:
	static LRESULT CALLBACK _HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK _HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	static constexpr LPCTSTR pClassName = L"Engine";
	HINSTANCE hInst = nullptr;

public:
public:
	Keyboard kbd;
};
