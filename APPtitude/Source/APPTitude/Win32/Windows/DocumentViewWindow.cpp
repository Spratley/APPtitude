#include "DocumentViewWindow.h"

bool DocumentViewWindow::Load(LPCWSTR path)
{
    if (m_loaded)
    {
        if (!Unload())
        {
            return false;
        }
    }

    if (LoadImpl())
    {
        m_loaded = true;
        return true;
    }
    return false;
}
