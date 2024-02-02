#pragma once

#include "Window.h"

class Menubar;

class MainWindow : public Window
{
public:
    MainWindow(LPCWSTR windowClass, LPCWSTR windowTitle);

    Menubar* const InitMenu();
    Menubar* const GetMenu() const { return m_menu; }
    void DeleteMenu() { /* IMPEMENT ME */ }

private:
    Menubar* m_menu = nullptr;
};