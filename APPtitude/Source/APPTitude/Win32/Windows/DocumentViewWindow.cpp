#include "DocumentViewWindow.h"

bool DocumentViewWindow::New()
{
    if (m_loaded)
    {
        if (!Unload())
        {
            return false;
        }
    }

    if (NewImpl())
    {
        m_loaded = true;
        return true;
    }
    return false;
}

bool DocumentViewWindow::Load(LPCWSTR path)
{
    if (m_loaded)
    {
        if (!Unload())
        {
            return false;
        }
    }

    if (LoadImpl(path))
    {
        m_path = std::wstring(path);
        m_loaded = true;
        return true;
    }
    return false;
}

bool DocumentViewWindow::Unload()
{
    if (!m_loaded)
    {
        return true;
    }

    if (UnloadImpl())
    {
        m_loaded = false;
        m_path = L"";
        return true;
    }
    return false;
}

bool DocumentViewWindow::Save()
{
    if (!m_loaded)
    {
        if (m_path == L"")
        {
            // SaveAs dialogue
        }
        return false;
    }

    if (SaveImpl())
    {
        m_hasUnsavedChanges = false;
        return true;
    }
    return false;
}
