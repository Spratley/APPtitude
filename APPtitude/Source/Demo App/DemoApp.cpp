#include "DemoApp.h"

bool DemoApp::Init(HINSTANCE const instanceHandle, int const cmdShow)
{
    // Set app window name
    m_appTitle = L"Demo App";

    return APPtitudeApp::Init(instanceHandle, cmdShow);
}