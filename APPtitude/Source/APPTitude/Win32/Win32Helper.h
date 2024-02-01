#pragma once

#include "../StandardIncludes.h"

namespace Win32Helper
{
    HWND CreateWindowGeneric(LPCWSTR const className, LPCWSTR const title, DWORD const style, HWND const parentHandle, int const posX = 0, int const posY = 0, int const width = 0, int const height = 0);
    HWND CreateMainWindow(LPCWSTR const className, LPCWSTR const title);
    HWND CreateChildWindow(LPCWSTR const className, LPCWSTR const title, DWORD const style, HWND const parentHandle, int const posX = 0, int const posY = 0, int const width = 0, int const height = 0);

    ATOM RegisterWindowClass(LPCWSTR const className, UINT const style, WNDPROC const callbackHandler, HBRUSH const backgroundBrush);
}