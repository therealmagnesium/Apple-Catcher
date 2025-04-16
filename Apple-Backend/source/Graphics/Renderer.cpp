#include "Graphics/Renderer.h"
#include "Core/Application.h"

#include <raylib.h>

namespace Apple
{
    namespace Graphics
    {
        static bool isInitialized = false;
        static RenderState state;

        void RendererInit()
        {
            const Core::ApplicationConfig& appInfo = Core::GetApplicationInfo();

            InitWindow(appInfo.windowWidth, appInfo.windowHeight, appInfo.name.c_str());
            SetTargetFPS(60);
        }

        void RendererShutdown()
        {
            TraceLog(LOG_INFO, "Shutting down the renderer...");
            CloseWindow();
        }

        void RendererBegin()
        {
            BeginDrawing();
            ClearBackground(state.clearColor);
        }

        void RendererEnd()
        {
            EndDrawing();
        }

        Camera* GetPrimaryCamera()
        {
            return state.primaryCamera;
        }

        void SetClearColor(u8 r, u8 g, u8 b)
        {
            state.clearColor.r = r;
            state.clearColor.g = g;
            state.clearColor.b = b;
            state.clearColor.a = 0xFF;
        }
    }
}
