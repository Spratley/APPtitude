#include "Window.h"
#include "ChildWindow.h"

#define MAX_WINDOW_TITLE_LENGTH 100

ChildWindow* Window::CreateChild() const
{
    // TODO: Track children?
    ChildWindow::CreateNewWindow(m_windowHandle, )
}

void Window::SetPosition(POINT pos)
{
    m_pos = pos;
    MoveWindow(m_windowHandle, pos.x, pos.y, m_size.x, m_size.y, true);
}

void Window::SetSize(POINT size)
{
    m_size = size;
    MoveWindow(m_windowHandle, m_pos.x, m_pos.y, size.x, size.y, true);
}

void Window::SetWindowTitle(std::wstring const & title)
{
    SetWindowText(m_windowHandle, title.c_str());
}

std::wstring Window::GetWindowTitle() const
{
    WCHAR title[MAX_WINDOW_TITLE_LENGTH];
    GetWindowText(m_windowHandle, title, MAX_WINDOW_TITLE_LENGTH);
    return std::wstring();
}

void Window::InvalidatePaintArea() const
{
    RECT rect;
    GetClientRect(m_windowHandle, &rect);
    InvalidateRect(m_windowHandle, &rect, true);
}
