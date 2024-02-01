#pragma once

#include "../StandardIncludes.h"

class Window
{
public:
    bool const IsValid() const { return m_windowHandle; }

    HWND GetHandle() const { return m_windowHandle; }

protected:
    HWND m_windowHandle;
};