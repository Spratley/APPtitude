#include "Win32Helper.h"

#include "../APPtitude.h"

#include "Window.h"

HWND Win32Helper::CreateMainWindow(LPCWSTR const windowClass, LPCWSTR const windowTitle)
{
    Window window(windowClass, windowTitle);
    return CreateWindowW(windowClass, windowTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, APPtitudeApp::GetInstanceHandle(), nullptr);
}

void Win32Helper::RegisterWindowClass(LPCWSTR const className, UINT const style, WNDPROC const callbackHandler, HBRUSH const backgroundBrush)
{
    WNDCLASSEXW windowClass;

    HINSTANCE instanceHandle = APPtitudeApp::GetInstanceHandle();

    windowClass.cbSize = sizeof(WNDCLASSEX);

    windowClass.style = style;
    windowClass.lpfnWndProc = callbackHandler;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = instanceHandle;
    windowClass.hIcon = LoadIcon(instanceHandle, MAKEINTRESOURCE(ID_APP_ICON));
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    windowClass.hbrBackground = backgroundBrush;
    windowClass.lpszMenuName = MAKEINTRESOURCEW(IDC_APPTITUDE);
    windowClass.lpszClassName = szWindowClass;
    windowClass.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(ID_APP_ICON));

    RegisterClassExW(&wcex);
}
