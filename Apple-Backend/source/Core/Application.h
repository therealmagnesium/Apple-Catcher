#pragma once
#include "Core/Base.h"

#include <raylib.h>
#include <string>

namespace Apple
{
    namespace Core
    {
        struct ApplicationConfig
        {
            std::string name = "Untitled";
            std::string author = "";
            u32 windowWidth = 1280;
            u32 windowHeight = 720;
        };

        struct Application
        {
            ApplicationConfig config;

            void (*OnCreate)() = NULL;
            void (*OnUpdate)() = NULL;
            void (*OnRender)() = NULL;
            void (*OnRenderUI)() = NULL;
            void (*OnShutdown)() = NULL;
        };

        struct ApplicationState
        {
            bool isRunning = false;
            Application* handle = NULL;
        };

        void SetupApplication(Application* app);
        void RunApplication();
        void QuitApplication();

        bool IsApplicationRunning();
        ApplicationConfig& GetApplicationInfo();
    }
}
