#include "DemoApp.h"

#include "../APPTitude/Win32/MainWindow.h"
#include "../APPTitude/Win32/Menubar/Menubar.h"

#define DEMOAPP_COMMAND_SAVE 200
#define DEMOAPP_COMMAND_SAVE_AS 201
#define DEMOAPP_COMMAND_OPEN 202
#define DEMOAPP_COMMAND_NEW 203

LRESULT DemoApp::MainWindowCallbackHandler(WIN32_CALLBACK_PARAMS)
{
    switch (message)
    {
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}

bool DemoApp::Init(HINSTANCE const instanceHandle, int const cmdShow)
{
    // Set app main window information
    m_appTitle = L"Demo App";
    m_mainWindowCallback = DemoApp::MainWindowCallbackHandler;
    m_mainWindowBrush = (HBRUSH)(COLOR_WINDOW + 1);

    if (!APPtitudeApp::Init(instanceHandle, cmdShow))
    {
        return false;
    }

    Menubar* const menubar = GetMainWindowMenu();
    LPCWSTR fileMenuName = L"File";
    menubar->InsertItem(fileMenuName, L"New", DEMOAPP_COMMAND_NEW);
    menubar->InsertBreak(fileMenuName);
    menubar->InsertItem(fileMenuName, L"Save", DEMOAPP_COMMAND_SAVE);
    menubar->InsertItem(fileMenuName, L"Save As...", DEMOAPP_COMMAND_SAVE_AS);
    menubar->InsertBreak(fileMenuName);
    menubar->InsertItem(fileMenuName, L"Open...", DEMOAPP_COMMAND_OPEN);
    menubar->InvalidateMenuBar();
    


    return true;
}