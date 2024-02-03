#include "APPtitude.h"

#include "Win32/MainWindow.h"
#include "Win32/Win32Helper.h"
#include <strsafe.h>

APPtitudeApp* APPtitudeApp::s_instance = nullptr;

bool APPtitudeApp::Init(HINSTANCE const instanceHandle, int const cmdShow)
{
    _ASSERT(!s_instance);
    s_instance = this;

    m_instanceHandle = instanceHandle;

    LPCWSTR const mainWindowClass = L"MainWindowClass";
    Win32Helper::RegisterWindowClass(mainWindowClass, CS_VREDRAW | CS_HREDRAW, m_mainWindowCallback, m_mainWindowBrush);
    m_mainWindow = new MainWindow(mainWindowClass, m_appTitle.c_str());

    ShowWindow(m_mainWindow->GetHandle(), cmdShow);
    UpdateWindow(m_mainWindow->GetHandle());
    return true;
}

int APPtitudeApp::Run()
{
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

Menubar * const APPtitudeApp::GetMainWindowMenu() const
{
    return m_mainWindow->InitMenu();
}
