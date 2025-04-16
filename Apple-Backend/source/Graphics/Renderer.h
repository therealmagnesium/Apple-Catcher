#pragma once
#include "Core/Base.h"
#include <raylib.h>

namespace Apple
{
    namespace Graphics
    {
        struct RenderState
        {
            Color clearColor = RAYWHITE;
            Camera* primaryCamera = NULL;
            Shader* primaryShader = NULL;
        };

        void RendererInit();
        void RendererShutdown();
        void RendererBegin();
        void RendererEnd();

        Camera* GetPrimaryCamera();

        void SetClearColor(u8 r, u8 g, u8 b);
        void SetPrimaryCamera(Camera* camera);
    }
}
