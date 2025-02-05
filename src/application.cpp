#include "constants.hpp"
#include "application.hpp"
#include "core_system/algorithms/algorithm_factory.hpp"
#include <iostream>

#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>

namespace SortingVisualizer
{
    Application::Application() 
        : shuffler(array) 
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);

        using namespace Constants::Window;
        InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, TITLE);
        SetWindowMinSize(INITIAL_WIDTH, INITIAL_HEIGHT);
        
        this->sorting_strategy = AlgorithmFactory::GetInstance().CreateAlgorithm(controls.GetAlgorithmType(), array);
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
        // The user may update the number of visible elements only if he isn't running any sorting algorithms.
        if (!this->run_shuffler && !this->run_sort)
            this->array.SetNumberOfVisibleElements(this->controls.GetNumberOfElements());

        if (this->controls.WasRunAlgorithmBtnPressed())
        {
            std::cout << (int)controls.GetAlgorithmType() << std::endl;
            // Update the sorting strategy based on the control panel.
            this->sorting_strategy = AlgorithmFactory::GetInstance().CreateAlgorithm(controls.GetAlgorithmType(), array);

            // We first want to run the shuffler, then the actual sorting strategy.
            this->run_shuffler = true;    
            this->run_sort = false;
            this->shuffler.Reset();
        }
        
        if (this->controls.WasStopAlgorithmBtnPressed())
        {
            // Stop both the shuffler and sorting strategy.
            this->run_shuffler = false;
            this->run_sort = false;
        }
    }

    void Application::UpdateLogic()
    {
        this->array.ResetFocus();

        if (this->run_shuffler)
        {
            if (this->shuffler.IsDone())
            {
                // If the shuffler has funished, prepare to run the actual sorting algorithm.
                this->run_shuffler = false;
                this->sorting_strategy->Reset(); 
                this->run_sort = true;
            }
            else 
            {
                this->shuffler.Step();
            }
        }
        
        // Step through sorting strategy.
        if (this->run_sort)
        {
            if (this->sorting_strategy->IsDone())
                this->run_sort = false;
            else
                this->sorting_strategy->Step();
        }        
    }

    void Application::run()
    {
        float delta_time_accumulator = 0.0f;

        while (!WindowShouldClose())
        {
            RenderGraphics();
            HandleUserInput();
            
            // Update logic at a fixed rate, (1/DELTA_TIME) times per second, regardless of the frame rate. And also remember that logic update has occured.
            delta_time_accumulator += GetFrameTime();
            while (delta_time_accumulator >= Constants::Application::DELTA_TIME)
            {
                delta_time_accumulator -= Constants::Application::DELTA_TIME;
                UpdateLogic(); 
            }
        }
    }
}