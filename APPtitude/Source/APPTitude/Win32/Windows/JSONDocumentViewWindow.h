#pragma once

#include "DocumentViewWindow.h"

#include "../../../JParse/JParse.h"

class JSONDocumentViewWindow : public DocumentViewWindow
{
public:

private:
    bool NewImpl() override;
    bool LoadImpl(LPCWSTR path) override;
    bool UnloadImpl() override;
    bool SaveImpl() override;

private:
    JParse::Root m_document;
};