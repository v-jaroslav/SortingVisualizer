#ifndef SORTING_VISUALIZER_USER_INTERFACE_CONTROL_PANEL_HPP
#define SORTING_VISUALIZER_USER_INTERFACE_CONTROL_PANEL_HPP

#include <raygui.h>

#include "constants.hpp"
#include "core_system/algorithms/algorithm_factory.hpp"

namespace SortingVisualizer::UserInterface
{
    // We have these functions here, because raygui.h header library doesn't work properly on HighDPI screens.
    float GetScaledWidth();
    float GetScaledHeight();

    class ControlPanel
    {
    private:
        float panel_height = 0;
        bool show_panel = true;
        bool show_algorithm_dropdown = false;
        bool show_mute_button = true;

        float number_of_elements = Constants::Application::MIN_NUM_OF_ELEMS;
        
        using AlgorithmType = CoreSystem::Algorithms::AlgorithmFactory::AlgorithmType;
        AlgorithmType algorithm_type = AlgorithmType::BUBBLE_SORT;
        
        bool run_algorithm = false;
        bool stop_algorithm = false;
        bool mute_audio = false;
        bool play_audio = false;

        void DrawControls(const Rectangle& relative_to);
        bool GetAndClear(bool& flag);

    public:
        void Draw();
        
        int GetNumberOfElements() const;
        AlgorithmType GetAlgorithmType() const;
        
        bool WasRunAlgorithmBtnPressed();
        bool WasStopAlgorithmBtnPressed();
        bool WasMuteAudioBtnPressed();
        bool WasPlayAudioBtnPressed();
    };
}

#endif