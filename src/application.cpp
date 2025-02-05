#include "application.hpp"
#include "constants.hpp"

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

#include <thread>
#include <chrono>

namespace SortingVisualizer
{
    Application::Application() 
        : shuffler(array)
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);

        using namespace Constants::Window;
        InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, TITLE);
        SetWindowMinSize(INITIAL_WIDTH, INITIAL_HEIGHT);
    }

    void Application::RenderGraphics()
    {
        BeginDrawing();
        ClearBackground(BLACK);
        
        // Draw the control panel last, so that it is on top of everything.
        this->array.Draw();
        this->controls.Draw();
            
        EndDrawing();
    }

    void Application::HandleUserInput()
    {
        this->array.SetNumberOfVisibleElements(this->controls.GetNumberOfElements());

        if (this->controls.WasRunAlgorithmBtnPressed())
        {
            
        }
    }

    void Application::UpdateLogic()
    {

    }

    void Application::run()
    {
        float delta_time_accumulator = 0.0f;

        while (!WindowShouldClose())
        {
            RenderGraphics();
            HandleUserInput();
            
            // Update logic at a fixed rate, (1/DELTA_TIME) times per second, regardless of the frame rate.
            delta_time_accumulator += GetFrameTime();
            while (delta_time_accumulator >= Constants::Application::DELTA_TIME)
            {
                delta_time_accumulator -= Constants::Application::DELTA_TIME;
                UpdateLogic(); 
            }
        }
    }
}