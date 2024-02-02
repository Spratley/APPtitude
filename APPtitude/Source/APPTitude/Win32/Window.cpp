#include "Window.h"

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
