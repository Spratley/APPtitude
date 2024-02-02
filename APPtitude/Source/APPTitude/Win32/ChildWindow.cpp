#include "ChildWindow.h"

#include "Win32Helper.h"

ChildWindow::ChildWindow(Window* parentWindow)
: m_parentWindow(parentWindow)
{ }

void ChildWindow::InitWindow(LPCWSTR windowClass, LPCWSTR windowTitle)
{
    m_windowHandle = Win32Helper::CreateChildWindow(windowClass, windowTitle, GetWindowStyle(), m_parentWindow->GetHandle());
}
