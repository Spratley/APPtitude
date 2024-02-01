#include "APPtitude.h"

#include "Win32/MainWindow.h"
#include "Win32/Win32Helper.h"
#include <strsafe.h>

APPtitudeApp* APPtitudeApp::s_instance = nullptr;

bool APPtitudeApp::Init(HINSTANCE const instanceHandle, int const cmdShow)
{
    _ASSERT(!s_instance);
    s_instance = this;

    m_instanceHandle = instanceHandle;

    LPCWSTR const mainWindowClass = L"MainWindowClass";
    Win32Helper::RegisterWindowClass(mainWindowClass, CS_VREDRAW | CS_HREDRAW, m_mainWindowCallback, m_mainWindowBrush);
    m_mainWindow = new MainWindow(mainWindowClass, m_appTitle.c_str());

    if (!m_mainWindow || !m_mainWindow->IsValid())
    {
        LPVOID lpMsgBuf;
        LPVOID lpDisplayBuf;
        DWORD dw = GetLastError();

        FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER |
            FORMAT_MESSAGE_FROM_SYSTEM |
            FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL,
            dw,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
            (LPTSTR)&lpMsgBuf,
            0, NULL);

        // Display the error message and exit the process

        lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT, (lstrlen((LPCTSTR)lpMsgBuf) + 40) * sizeof(TCHAR));
        StringCchPrintf((LPTSTR)lpDisplayBuf, LocalSize(lpDisplayBuf) / sizeof(TCHAR), TEXT("Failed with error %d: %s"),dw, lpMsgBuf);
        MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

        LocalFree(lpMsgBuf);
        LocalFree(lpDisplayBuf);
        return false;
    }

    ShowWindow(m_mainWindow->GetHandle(), cmdShow);
    UpdateWindow(m_mainWindow->GetHandle());
    return true;
}

int APPtitudeApp::Run()
{
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}