#include "Core/Application.h"
#include "Core/Base.h"

#include "Graphics/Renderer.h"

#include <raylib.h>
#include <time.h>

namespace Apple
{
    namespace Core
    {
        static bool isInitialized = false;
        static ApplicationState state;

        void SetupApplication(Application* app)
        {
            if (isInitialized)
            {
                TraceLog(LOG_WARNING, "Cannot initialize application more than once!");
                return;
            }

            srand(time(NULL));

            state.isRunning = true;
            state.handle = app;

            Graphics::RendererInit();

            isInitialized = true;
            TraceLog(LOG_INFO, "The application was initialized successfully");
        }

        void RunApplication()
        {
            state.handle->OnCreate();

            while (state.isRunning)
            {
                state.isRunning = !WindowShouldClose();
                state.handle->OnUpdate();

                Graphics::RendererBegin();

                state.handle->OnRender();
                state.handle->OnRenderUI();

                Graphics::RendererEnd();
            }

            state.handle->OnShutdown();
            Graphics::RendererShutdown();
        }

        void QuitApplication()
        {
            TraceLog(LOG_INFO, "Exiting the application...");
            state.isRunning = false;
        }

        bool IsApplicationRunning()
        {
            return state.isRunning;
        }

        ApplicationConfig& GetApplicationInfo()
        {
            return state.handle->config;
        }
    }
}
