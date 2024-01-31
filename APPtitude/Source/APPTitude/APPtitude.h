#pragma once

#include "StandardIncludes.h"

#include <string>

class Window;

class APPtitudeApp
{
public:
    static HINSTANCE GetInstanceHandle() { return s_instanceHandle; }
    static Window& GetMainWindowHandle() { return *s_mainWindowHandle; }

private:
    static HINSTANCE s_instanceHandle;
    static Window* s_mainWindowHandle;

public:
    virtual bool Init(HINSTANCE const instanceHandle, int const cmdShow);

    int Run();

protected:
    std::wstring m_appTitle;
};