#include "APPTitude/StandardIncludes.h"

// Replace with your app header
#include "Demo App/DemoApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    DemoApp app;
    app.Init(hInstance, nCmdShow);
    return app.Run();
}