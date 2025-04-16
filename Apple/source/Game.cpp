#include "Game.h"

#include <Apple.h>
#include <raylib.h>

using namespace Apple;
using namespace Apple::Core;
using namespace Apple::Graphics;

void Apple_OnCreate()
{
    SetClearColor(15, 15, 15);
}

void Apple_OnUpdate()
{
}

void Apple_OnRender()
{
    DrawFPS(20, 20);
}

void Apple_OnRenderUI()
{
}

void Apple_OnShutdown()
{
}
