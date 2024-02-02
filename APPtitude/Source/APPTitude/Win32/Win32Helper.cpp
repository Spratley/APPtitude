#include "Win32Helper.h"

#include "../APPtitude.h"

#include "Window.h"

HWND Win32Helper::CreateWindowGeneric(LPCWSTR const className, LPCWSTR const title, DWORD const style, HWND const parentHandle, int const posX, int const posY, int const width, int const height)
{
    return CreateWindow(className, title, style, posX, posY, width, height, parentHandle, NULL, APPtitudeApp::GetInstanceHandle(), NULL);
}

HWND Win32Helper::CreateMainWindow(LPCWSTR const className, LPCWSTR const title)
{
    return CreateWindowGeneric(className, title, WS_OVERLAPPEDWINDOW, nullptr, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT);
}

HWND Win32Helper::CreateChildWindow(LPCWSTR const className, LPCWSTR const title, DWORD const style, HWND const parentHandle, int const posX, int const posY, int const width, int const height)
{
    return CreateWindowGeneric(className, title, style | WS_CHILD | WS_VISIBLE, parentHandle, posX, posY, width, height);
}

ATOM Win32Helper::RegisterWindowClass(LPCWSTR const className, UINT const style, WNDPROC const callbackHandler, HBRUSH const backgroundBrush)
{
    HINSTANCE instanceHandle = APPtitudeApp::GetInstanceHandle();

    WNDCLASSEXW windowClass {};
    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = style;
    windowClass.lpfnWndProc = callbackHandler;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = instanceHandle;
    windowClass.hIcon = LoadIcon(instanceHandle, MAKEINTRESOURCE(ID_APP_ICON));
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    windowClass.hbrBackground = backgroundBrush;
    windowClass.lpszMenuName = APPtitudeApp::GetMainWindowTitle().c_str();
    windowClass.lpszClassName = className;
    windowClass.hIconSm = LoadIcon(instanceHandle, MAKEINTRESOURCE(ID_APP_ICON));

    return RegisterClassExW(&windowClass);
}
