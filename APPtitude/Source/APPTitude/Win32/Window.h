#pragma once

#include "../StandardIncludes.h"

class Window
{
public:
    Window(LPCWSTR windowClass, LPCWSTR windowTitle);

    HWND GetHandle() const { return m_windowHandle; }

private:
    HWND m_windowHandle;
};