#include "application.hpp"
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
        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(BLACK);
            
            this->array.SetNumberOfVisibleElements(this->controls.GetNumberOfElements());
            this->array.Draw();

            // Draw the control panel last, so that it is on top of everything.
            this->controls.Draw();

            EndDrawing();
        }
    }
}