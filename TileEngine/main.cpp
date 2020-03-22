#include "Game.h"
#include "Window.h"



int CALLBACK WinMain(
    HINSTANCE hInst,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd
)
{
    try
    {
        Window wnd(hInst);
        try
        {
            Game theGame(wnd);
            while (wnd.ProcessMessage())
            {
                theGame.Go();
            }
        }
        catch (const EngineException & e)
        {
            const std::wstring eMsg = e.GetFullMessage() +
                L"\n\nException caught at Windows message loop.";
            wnd.ShowMessageBox(e.GetExceptionType(), eMsg, MB_ICONERROR);
        }
        catch (const std::exception & e)
        {
            // need to convert std::exception what() string from narrow to wide string
            const std::string whatStr(e.what());
            const std::wstring eMsg = std::wstring(whatStr.begin(), whatStr.end()) +
                L"\n\nException caught at Windows message loop.";
            wnd.ShowMessageBox(L"Unhandled STL Exception", eMsg, MB_ICONERROR);
        }
        catch (...)
        {
            wnd.ShowMessageBox(L"Unhandled Non-STL Exception",
                L"\n\nException caught at Windows message loop.", MB_ICONERROR);
        }
    }
    catch (const EngineException & e)
    {
        const std::wstring eMsg = e.GetFullMessage() +
            L"\n\nException caught at main window creation.";
        MessageBox(nullptr, eMsg.c_str(), e.GetExceptionType().c_str(), MB_ICONERROR);
    }
    catch (const std::exception & e)
    {
        // need to convert std::exception what() string from narrow to wide string
        const std::string whatStr(e.what());
        const std::wstring eMsg = std::wstring(whatStr.begin(), whatStr.end()) +
            L"\n\nException caught at main window creation.";
        MessageBox(nullptr, eMsg.c_str(), L"Unhandled STL Exception", MB_ICONERROR);
    }
    catch (...)
    {
        MessageBox(nullptr, L"\n\nException caught at main window creation.",
            L"Unhandled Non-STL Exception", MB_ICONERROR);
    }

    return 0;
}