#pragma once

#include "Window.h"

class ChildWindow : public Window
{
public:
    template<typename T>
    static T* CreateNewWindow(Window* const parentWindow, LPCWSTR windowClass, LPCWSTR windowTitle);

public:
    ChildWindow(Window* parentWindow);
    void InitWindow(LPCWSTR windowClass, LPCWSTR windowTitle);

    virtual DWORD GetWindowStyle() const { return 0; }

private:
    Window* m_parentWindow;
};

template<typename T>
inline T * ChildWindow::CreateNewWindow(Window* const parentWindow, LPCWSTR windowClass, LPCWSTR windowTitle)
{
    T* window = new T(parentWindow);
    window->InitWindow(windowClass, windowTitle);
    return window;
}
