#pragma once

#include "Window.h"

class ChildWindow : public Window
{
public:
    ChildWindow(LPCWSTR windowClass, LPCWSTR windowTitle, Window* parentWindow);

private:
    Window* m_parentWindow;
};