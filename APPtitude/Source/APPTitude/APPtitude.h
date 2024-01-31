#pragma once

#include "StandardIncludes.h"

#include <string>

class Window;

class APPtitudeApp
{
public:
    static HINSTANCE GetInstanceHandle() { return s_instance->m_instanceHandle; }
    static Window& GetMainWindowHandle() { return *s_instance->m_mainWindowHandle; }

    static std::wstring const& GetMainWindowTitle() { return s_instance->m_appTitle; }

private:
    static APPtitudeApp* s_instance;

public:
    virtual bool Init(HINSTANCE const instanceHandle, int const cmdShow);

    int Run();

private:
    HINSTANCE m_instanceHandle;
    Window* m_mainWindowHandle;

protected:
    std::wstring m_appTitle;
};