#pragma once

#include "../StandardIncludes.h"

class Window
{
public:
    bool const IsValid() const { return m_windowHandle; }

    HWND GetHandle() const { return m_windowHandle; }

    void SetPosition(POINT pos);
    void SetSize(POINT size);

    POINT const& GetPos() const { return m_pos; }
    POINT const& GetSize() const { return m_size; }

protected:
    HWND m_windowHandle;

    POINT m_pos;
    POINT m_size;
};