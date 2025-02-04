#include "application.hpp"
#include "control_panel.hpp"
#include "constants.hpp"

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

namespace SortingVisualizer
{
    Application::Application()
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);

        using namespace Constants::Window;
        InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, TITLE);
        SetWindowMinSize(INITIAL_WIDTH, INITIAL_HEIGHT);
    }

    void Application::run()
    {
        UserInterface::ControlPanel controls;

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(BLACK);
            
            controls.draw();

            EndDrawing();
        }
    }
}