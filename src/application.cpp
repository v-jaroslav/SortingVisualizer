#include "constants.hpp"
#include "application.hpp"

#include "core_system/tone_generator.hpp"

// One translation unit must have a raygui implementation, conditional compilation.
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>
#include <raylib.h>

namespace SortingVisualizer
{
    Application::Application() 
        : shuffler(array), run_shuffler(false), run_sort(false), play_sound(true)
    {
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT);

        using namespace Constants::Window;
        InitWindow(INITIAL_WIDTH, INITIAL_HEIGHT, TITLE);
        SetWindowMinSize(INITIAL_WIDTH, INITIAL_HEIGHT);
        
        this->sorting_strategy = AlgorithmFactory::GetInstance().CreateAlgorithm(controls.GetAlgorithmType(), array);

        CoreSystem::ToneGenerator::Initialize();
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
        // The user may update the number of visible elements only if he isn't running any sorting algorithm.
        if (!this->run_shuffler && !this->run_sort)
            this->array.SetNumberOfVisibleElements(this->controls.GetNumberOfElements());

        if (this->controls.WasRunAlgorithmBtnPressed())
        {
            if (play_sound)
                CoreSystem::ToneGenerator::Play();

            // Update the sorting strategy based on the control panel.
            this->sorting_strategy = AlgorithmFactory::GetInstance().CreateAlgorithm(controls.GetAlgorithmType(), array);

            // We first want to run the shuffler, then the actual sorting strategy.
            this->shuffler.Reset();
            this->run_shuffler = true;
            this->run_sort = false;
        }
        
        if (this->controls.WasStopAlgorithmBtnPressed())
        {
            // Stop both the shuffler and sorting strategy.
            this->run_sort = this->run_shuffler = false;
            CoreSystem::ToneGenerator::Stop();
        }
        
        if (this->controls.WasMuteAudioBtnPressed())
        {
            this->play_sound = false;
            CoreSystem::ToneGenerator::Stop();
        }

        if (this->controls.WasPlayAudioBtnPressed())
        {
            this->play_sound = true;
            if (this->run_shuffler || this->run_sort)
                CoreSystem::ToneGenerator::Play();
        }
    }

    void Application::UpdateLogic()
    {
        // Reset focus of array elements whenever logic is being updated, and not when we are rendering frames, as algorithms which are ran in the UpdateLogic change the focus of elements exactly here.
        // We do not do that in RenderGraphics(), as that function may be called multiple times, before UpdateLogic() is, and therefore some elements won't stay focused long enough, and we would have flashing effect.
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
            {
                this->run_sort = false;
                CoreSystem::ToneGenerator::Stop();
            }
            else
            {
                this->sorting_strategy->Step();
            }
        }        
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