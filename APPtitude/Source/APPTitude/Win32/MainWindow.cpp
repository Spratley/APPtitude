#include "MainWindow.h"

#include "Win32Helper.h"

MainWindow::MainWindow(LPCWSTR windowClass, LPCWSTR windowTitle)
{
    Win32Helper::CreateMainWindow(windowClass, windowTitle);
}
