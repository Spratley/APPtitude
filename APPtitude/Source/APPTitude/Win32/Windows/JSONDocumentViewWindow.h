#pragma once

#include "DocumentViewWindow.h"

#include "../Win32Defines.h"
#include "../../../JParse/JParse.h"

class JSONDocumentViewWindow : public DocumentViewWindow
{
DECLARE_WINDOW_CLASS
public:
    static LRESULT CALLBACK JSONDocumentViewWindowCallbackHandler(WIN32_CALLBACK_PARAMS);

private:
    bool NewImpl() override;
    bool LoadImpl(LPCWSTR path) override;
    bool UnloadImpl() override;
    bool SaveImpl() override;

private:
    JParse::Root m_document;
};