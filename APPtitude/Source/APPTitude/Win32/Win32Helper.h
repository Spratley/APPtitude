#pragma once

#include "../StandardIncludes.h"

namespace Win32Helper
{
    HWND CreateMainWindow(LPCWSTR const windowClass, LPCWSTR const windowTitle);
    HWND CreateChildWindow();

    void RegisterWindowClass(LPCWSTR const className, UINT const style, WNDPROC const callbackHandler, HBRUSH const backgroundBrush);
}