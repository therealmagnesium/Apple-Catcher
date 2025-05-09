#pragma once
#include <Apple.h>

using namespace Apple;
using namespace Apple::Core;

struct GameState
{
    Camera camera;
};

void Apple_OnCreate();
void Apple_OnUpdate();
void Apple_OnRender();
void Apple_OnRenderUI();
void Apple_OnShutdown();
