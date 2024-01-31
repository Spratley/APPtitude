#pragma once

#include "Window.h"

class ChildWindow : public Window
{
public:
    ChildWindow(LPCWSTR windowClass, LPCWSTR windowTitle, HWND parentWindowHandle);

private:
    HWND m_parentWindowHandle;
};