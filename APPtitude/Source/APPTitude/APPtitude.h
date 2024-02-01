#pragma once

#include "StandardIncludes.h"

#include <string>

class MainWindow;

class APPtitudeApp
{
public:
    static HINSTANCE GetInstanceHandle() { return s_instance->m_instanceHandle; }
    static MainWindow& GetMainWindow() { return *s_instance->m_mainWindow; }

    static std::wstring const& GetMainWindowTitle() { return s_instance->m_appTitle; }

private:
    static APPtitudeApp* s_instance;

public:
    virtual bool Init(HINSTANCE const instanceHandle, int const cmdShow);

    int Run();

private:
    HINSTANCE m_instanceHandle;
    MainWindow* m_mainWindow;

protected:
    std::wstring m_appTitle;
    WNDPROC m_mainWindowCallback;
    HBRUSH m_mainWindowBrush;
};