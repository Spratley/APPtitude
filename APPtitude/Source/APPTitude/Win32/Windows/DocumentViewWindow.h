#pragma once

#include "../ChildWindow.h"
#include <string>

class DocumentViewWindow : public ChildWindow
{
public:
    bool New();
    bool Load(LPCWSTR path);
    bool Unload();

    bool Save();
    
protected:
    virtual bool NewImpl() = 0;
    virtual bool LoadImpl(LPCWSTR path) = 0;
    virtual bool UnloadImpl() = 0;
    virtual bool SaveImpl() = 0;

protected:
    bool m_loaded = false;
    bool m_hasUnsavedChanges = false;
    std::wstring m_path = nullptr;
};