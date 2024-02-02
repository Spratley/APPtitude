#include "MainWindow.h"

#include "Menubar/Menubar.h"
#include "Win32Helper.h"

MainWindow::MainWindow(LPCWSTR windowClass, LPCWSTR windowTitle)
{
    m_windowHandle = Win32Helper::CreateMainWindow(windowClass, windowTitle);
}

Menubar * const MainWindow::InitMenu()
{
    if (!m_menu)
    {
        m_menu = new Menubar(m_windowHandle);
    }
    return m_menu;
}
