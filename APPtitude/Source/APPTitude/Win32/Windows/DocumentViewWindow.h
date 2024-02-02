#pragma once

#include "../ChildWindow.h"

class DocumentViewWindow : public ChildWindow
{
public:
    bool Load(LPCWSTR path);
    virtual bool Unload() = 0;
    
protected:
    virtual bool LoadImpl() = 0;

protected:
    bool m_loaded = false;
};