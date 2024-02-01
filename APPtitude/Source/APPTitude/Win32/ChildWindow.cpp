#include "ChildWindow.h"

#include "Win32Helper.h"

ChildWindow::ChildWindow(LPCWSTR windowClass, LPCWSTR windowTitle, Window* parentWindow)
: m_parentWindow(parentWindow)
{
    // Create the window...
}