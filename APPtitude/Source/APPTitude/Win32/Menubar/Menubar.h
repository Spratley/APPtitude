#pragma once

#include "../../StandardIncludes.h"

#include <unordered_map>

struct MenuItem
{
    std::wstring m_name;
    UINT m_identifier;
};

struct MenuPopout
{
    std::wstring m_name;
    std::unordered_map<std::wstring, MenuItem> m_popoutContents;
    HMENU m_menuHandle;
};

class Menubar
{
public:
    Menubar(HWND ownerHandle);

    void InsertItem(std::wstring const& parentPopout, std::wstring const& itemName, UINT const identifier);
    void InvalidateMenuBar();

private:
    void CreatePopout(std::wstring const& name);

private:
    HWND m_owner = NULL;

    HMENU m_menuHandle = NULL;
    std::unordered_map<std::wstring, MenuPopout> m_menuContents;
};