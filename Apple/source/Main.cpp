#include "Game.h"

#include <EntryPoint.h>
#include <Apple.h>

using namespace Apple;
using namespace Apple::Core;

void Apple_EntryPoint(Application* app)
{
    app->config.name = "Apple Catcher";
    app->config.author = "Magnus Ahlstromer V";
    app->config.windowWidth = 1600;
    app->config.windowHeight = 900;

    app->OnCreate = Apple_OnCreate;
    app->OnUpdate = Apple_OnUpdate;
    app->OnRender = Apple_OnRender;
    app->OnRenderUI = Apple_OnRenderUI;
    app->OnShutdown = Apple_OnShutdown;
}
