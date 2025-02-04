#ifndef USER_INTERFACE_CONTROL_PANEL_HPP
#define USER_INTERFACE_CONTROL_PANEL_HPP

#include <raygui.h>

namespace UserInterface
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

        float number_of_elements = 0;
        int algorithm_type = 0;
        
        bool run_algorithm = false;
        bool stop_algorithm = false;
        bool shuffle_elements = false;
        bool mute_audio = false;
        bool play_audio = false;

        void DrawControls(const Rectangle& relative_to);
        bool GetAndClear(bool& flag);

    public:
        void Draw();
        
        int GetNumberOfElements() const;
        int GetAlgorithmType() const;
        
        bool WasRunAlgorithmBtnPressed();
        bool WasStopAlgorithmBtnPressed();
        bool WasShuffleElementsBtnPressed();
        bool WasMuteAudioBtnPressed();
        bool WasPlayAudioBtnPressed();
    };
}

#endif