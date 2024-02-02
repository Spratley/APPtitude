#include "Menubar.h"

Menubar::Menubar(HWND ownerHandle)
: m_owner(ownerHandle)
{
    m_menuHandle = CreateMenu();
    SetMenu(m_owner, m_menuHandle);
}

void Menubar::InsertItem(std::wstring const & parentPopout, std::wstring const & itemName, UINT const identifier)
{
    CreatePopout(parentPopout);
    AppendMenu(m_menuContents[parentPopout].m_menuHandle, MF_STRING, identifier, itemName.c_str());
}

void Menubar::InvalidateMenuBar()
{
    DrawMenuBar(m_owner);
}

void Menubar::CreatePopout(std::wstring const & name)
{
    if (m_menuContents.count(name) == 0)
    {
        MenuPopout popout;
        popout.m_name = name;
        popout.m_menuHandle = CreateMenu();
        AppendMenu(m_menuHandle, MF_STRING | MF_POPUP, (UINT)popout.m_menuHandle, name.c_str());
        m_menuContents[name] = popout;
    }
}
