#pragma once

#include "../StandardIncludes.h"

#include <string>

class ChildWindow;

class Window
{
public:
    bool const IsValid() const { return m_windowHandle; }

    HWND GetHandle() const { return m_windowHandle; }

    ChildWindow* CreateChild() const;

    void SetPosition(POINT pos);
    void SetSize(POINT size);

    POINT const& GetPos() const { return m_pos; }
    POINT const& GetSize() const { return m_size; }

    void SetWindowTitle(std::wstring const& title);
    std::wstring GetWindowTitle() const;

    void InvalidatePaintArea() const;

protected:
    HWND m_windowHandle;

    POINT m_pos;
    POINT m_size;
};