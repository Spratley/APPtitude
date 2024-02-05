#pragma once

#include "StandardIncludes.h"

#include "Win32/Window.h"
#include "Win32/Win32Helper.h"

#include <string>

class MainWindow;
class Menubar;

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

    Menubar* const GetMainWindowMenu() const;

protected:
    virtual void RegisterWindowClasses();

private:
    template<typename T>
    void RegisterWindowClass() const;

protected:
    HINSTANCE m_instanceHandle;
    MainWindow* m_mainWindow;

    std::wstring m_appTitle;
    WNDPROC m_mainWindowCallback;
    HBRUSH m_mainWindowBrush;
};

template<typename T>
inline void APPtitudeApp::RegisterWindowClass() const
{
    WindowClassData const windowClass = T::GetWindowClassData();
    Win32Helper::RegisterWindowClass(windowClass.className, windowClass.style, windowClass.callbackHandler, windowClass.backgroundBrush);
    T::s_windowClassName = std::wstring(windowClass.className);
}
