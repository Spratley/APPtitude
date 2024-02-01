#pragma once

#include "../APPTitude/APPtitude.h"

#include "../APPTitude/Win32/Win32Defines.h"

class DemoApp : public APPtitudeApp
{
public:
    static LRESULT CALLBACK MainWindowCallbackHandler(WIN32_CALLBACK_PARAMS);

public:
    bool Init(HINSTANCE const instanceHandle, int const cmdShow) override;

private:
};