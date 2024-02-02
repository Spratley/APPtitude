#include "MainWindow.h"

#include "Win32Helper.h"

MainWindow::MainWindow(LPCWSTR windowClass, LPCWSTR windowTitle)
{
    m_windowHandle = Win32Helper::CreateMainWindow(windowClass, windowTitle);
}
