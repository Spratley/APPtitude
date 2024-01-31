#include "ChildWindow.h"

ChildWindow::ChildWindow(LPCWSTR windowClass, LPCWSTR windowTitle, HWND parentWindowHandle)
: m_parentWindowHandle(parentWindowHandle)
, Window(windowClass, windowTitle)
{}
