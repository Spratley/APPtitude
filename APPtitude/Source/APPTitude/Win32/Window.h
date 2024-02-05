#pragma once

#include "../StandardIncludes.h"

#include <string>

#define DECLARE_WINDOW_CLASS public: static LPCWSTR const GetWindowClassName() { return s_windowClassName.c_str(); } static WindowClassData const GetWindowClassData(); static std::wstring s_windowClassName;

class ChildWindow;

struct WindowClassData
{
    WindowClassData() {}

    LPCWSTR className = NULL;
    UINT style = NULL;
    WNDPROC callbackHandler = NULL;
    HBRUSH backgroundBrush = NULL;
};

class Window
{
public:
    bool const IsValid() const { return m_windowHandle; }

    HWND GetHandle() const { return m_windowHandle; }

    template <typename WindowClass>
    WindowClass* CreateChild(LPCWSTR const windowName) const;

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

template<typename WindowClass>
inline WindowClass* Window::CreateChild(LPCWSTR const windowName) const
{
    ChildWindow* window = ChildWindow::CreateNewWindow(m_windowHandle, WindowClass::GetWindowClassName(), windowName);
    return static_cast<WindowClass*>(window);
}