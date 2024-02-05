#include "JSONDocumentViewWindow.h"

#include "../../StringConvert.h"

std::wstring JSONDocumentViewWindow::s_windowClassName = L"";

WindowClassData const JSONDocumentViewWindow::GetWindowClassData()
{
    WindowClassData data;
    data.className = L"JSONDocumentView";
    data.style = 0;
    data.callbackHandler = JSONDocumentViewWindowCallbackHandler;
    data.backgroundBrush = (HBRUSH)(COLOR_WINDOW + 1);
    return data;
}

LRESULT JSONDocumentViewWindow::JSONDocumentViewWindowCallbackHandler(WIN32_CALLBACK_PARAMS)
{
    return DefWindowProc(hWnd, message, wParam, lParam);
}

bool JSONDocumentViewWindow::NewImpl()
{
    m_document.CreateNew();
    return true;
}

bool JSONDocumentViewWindow::LoadImpl(LPCWSTR path)
{
    m_document.Parse(StringConvert::ToStr(std::wstring(path)));
    return true;
}

bool JSONDocumentViewWindow::UnloadImpl()
{
    m_document.CreateNew();
    return true;
}

bool JSONDocumentViewWindow::SaveImpl()
{
    m_document.SaveToFile(StringConvert::ToStr(std::wstring(m_path)));
    return true;
}
