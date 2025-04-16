#pragma once
#include "Core/Application.h"

extern void Apple_EntryPoint(Apple::Core::Application* app);

int main(int argc, char** argv)
{
    Apple::Core::Application app;
    Apple_EntryPoint(&app);

    if (app.OnCreate == NULL || app.OnUpdate == NULL || app.OnRender == NULL || app.OnRenderUI == NULL ||
        app.OnShutdown == NULL)
    {
        TraceLog(LOG_FATAL, "The application could not find references to it's function pointers!");
        return 1;
    }

    Apple::Core::SetupApplication(&app);
    Apple::Core::RunApplication();

    return 0;
}
