#include "Game.h"

#include <Apple.h>
#include <raylib.h>

using namespace Apple;
using namespace Apple::Core;
using namespace Apple::Graphics;

static GameState state;

void Apple_OnCreate()
{
    SetClearColor(15, 15, 15);

    state.camera.position = (vec3){0.f, 2.f, 3.f};
    state.camera.target = (vec3){0.f, 0.f, 0.f};
    state.camera.up = (vec3){0.f, 1.f, 0.f};
    state.camera.projection = CAMERA_PERSPECTIVE;
    state.camera.fovy = 45.f;
    SetPrimaryCamera(&state.camera);
}

void Apple_OnUpdate()
{
    if (IsKeyPressed(KEY_ESCAPE) && IsCursorHidden())
        EnableCursor();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && IsCursorOnScreen())
        DisableCursor();

    if (IsCursorHidden())
        UpdateCamera(&state.camera, CAMERA_FREE);
}

void Apple_OnRender()
{
    DrawGrid(50, 1.f);
    DrawSphere((vec3){0.f, 0.f, 0.f}, 0.5f, BLUE);
}

void Apple_OnRenderUI()
{
    DrawFPS(20, 20);
}

void Apple_OnShutdown()
{
}
