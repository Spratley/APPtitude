#include "JSONDocumentViewWindow.h"

#include "../../StringConvert.h"

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
