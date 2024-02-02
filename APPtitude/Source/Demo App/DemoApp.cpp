#include "DemoApp.h"

LRESULT DemoApp::MainWindowCallbackHandler(WIN32_CALLBACK_PARAMS)
{
    switch (message)
    {
    case WM_CREATE:
        // Lol I pushed this to keep my streak
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

bool DemoApp::Init(HINSTANCE const instanceHandle, int const cmdShow)
{
    // Set app main window information
    m_appTitle = L"Demo App";
    m_mainWindowCallback = DemoApp::MainWindowCallbackHandler;
    m_mainWindowBrush = (HBRUSH)(COLOR_WINDOW + 1);

    return APPtitudeApp::Init(instanceHandle, cmdShow);
}