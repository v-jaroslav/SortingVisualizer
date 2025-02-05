#include "control_panel.hpp"

namespace SortingVisualizer::UserInterface
{
    float GetScaledWidth()
    {
        // Read the HIGHDPI scale factor only once and store it in a static variable, as it is costly operation as you have to ask OS for that information.
        // It is not expected for user to change HIGHDPI settings randomly, if he does, he may just restart the app.
        static float x_scale = GetWindowScaleDPI().x;
        return GetRenderWidth() / x_scale;
    }

    float GetScaledHeight()
    {
        static float y_scale = GetWindowScaleDPI().y;
        return GetRenderHeight() / y_scale;
    }

    void ControlPanel::Draw()
    {
        using namespace Constants::UserInterface::ControlPanel;

        if (this->show_panel)
        {
            // Render the GuiWindowBox, and if the close button was pressed, then set the flag show_panel to be false, if it wasnt pressed, then we can freely render the controls in the panel.
            Rectangle window_box_bounds { MARGIN_PX, MARGIN_PX, GetScaledWidth() - 2*MARGIN_PX, this->panel_height };
            if (GuiWindowBox(window_box_bounds, STATUS_TITLE_OPEN))
                this->show_panel = false;
            else
                this->DrawControls(window_box_bounds); 
        }
        else
        {
            // If the control panel is supposed to be hidden, just draw it's status bar.
            Rectangle status_bar_bounds { MARGIN_PX, MARGIN_PX, GetScaledWidth() - 2*MARGIN_PX, STATUS_BAR_HEIGHT };
            GuiStatusBar(status_bar_bounds, STATUS_TITLE_CLOSED);
            
            // Also draw the button that will unhide it, that is centerd on y axis in the status bar, and is near the end of it (just like button on GuiWindowBox).
            // If you wonder how we set the x of the button, look at the raygui.h for GuiWindowBox, as they use the similar logic.
            // That same logic is applied here, as we want the button on the same position.
            Rectangle unhide_btn_bounds;
            unhide_btn_bounds.x = status_bar_bounds.x + status_bar_bounds.width - GuiGetStyle(BUTTON, BORDER_WIDTH) - (BUTTON_SIZE + 2);
            unhide_btn_bounds.y = status_bar_bounds.y + status_bar_bounds.height / 2 - BUTTON_SIZE / 2;
            unhide_btn_bounds.width = unhide_btn_bounds.height = BUTTON_SIZE;

            // If unhide button was clicked, set the flag to show the panel to be true again.
            GuiSetStyle(BUTTON, BORDER_WIDTH, 1);
            if (GuiButton(unhide_btn_bounds, "v"))
                this->show_panel = true;
        }
    }

    void ControlPanel::DrawControls(const Rectangle& relative_to)
    {
        using namespace Constants::UserInterface::ControlPanel;

        using Constants::Application::MIN_NUM_OF_ELEMS;
        using Constants::Application::MAX_NUM_OF_ELEMS;
        
        int font_size = GetFontDefault().baseSize;
        int quarter = relative_to.width / 4;
        int thirds = relative_to.width / 3;

        Rectangle first_row_bounds  { relative_to.x + MARGIN_PX,
                                      relative_to.y + STATUS_BAR_HEIGHT + MARGIN_PX,
                                      thirds - 2*MARGIN_PX,
                                      font_size + PADDING_PX };

        Rectangle second_row_bounds { relative_to.x + MARGIN_PX,
                                      first_row_bounds.y + first_row_bounds.height + MARGIN_PX,
                                      quarter - 2*MARGIN_PX,
                                      font_size + PADDING_PX };
        
        this->panel_height = second_row_bounds.y + second_row_bounds.height + MARGIN_PX;
        
        
        // Rendering second row.
        GuiSetStyle(LABEL, TEXT_ALIGNMENT, TEXT_ALIGN_RIGHT);
        GuiLabel(second_row_bounds, SLIDER_LABEL);
        
        second_row_bounds.x += quarter;
        GuiSlider(second_row_bounds, MIN_ELEMS_SLIDER, MAX_ELEMS_SLIDER, &this->number_of_elements, MIN_NUM_OF_ELEMS, MAX_NUM_OF_ELEMS);

        second_row_bounds.x += quarter;
        GuiLabel(second_row_bounds, SORTING_ALGORITHM_LABEL);
        
        second_row_bounds.x += quarter;
        if (GuiDropdownBox(second_row_bounds, ALGORITHM_OPTIONS, &algorithm_type, show_algorithm_dropdown))
            show_algorithm_dropdown = !show_algorithm_dropdown;


        // Rendering first row.
        GuiSetStyle(BUTTON, BORDER_WIDTH, 1);
        if (GuiButton(first_row_bounds, RUN_ALGORITHM_BTN))
            this->run_algorithm = true;
        
        first_row_bounds.x += thirds;
        if (GuiButton(first_row_bounds, STOP_ALGORITHM_BTN))
            this->stop_algorithm = true;

        // Show either the mute button or play audio button depending on which one was pressed last.
        first_row_bounds.x += thirds;
        if (show_mute_button && GuiButton(first_row_bounds, MUTE_AUDIO_BTN))
        {
            this->show_mute_button = false;
            this->mute_audio = true;
        }
        else if (!show_mute_button && GuiButton(first_row_bounds, PLAY_AUDIO_BTN))
        {
            this->show_mute_button = true;
            this->play_audio = true;
        }
    }
    
    bool ControlPanel::GetAndClear(bool& flag)
    {
        bool result = flag;
        flag = false;
        return result;
    }
    
    int ControlPanel::GetNumberOfElements() const
    {
        return this->number_of_elements;
    }

    int ControlPanel::GetAlgorithmType() const
    {
        return this->algorithm_type;
    }
    
    bool ControlPanel::WasRunAlgorithmBtnPressed()
    {
        return this->GetAndClear(this->run_algorithm);
    }

    bool ControlPanel::WasStopAlgorithmBtnPressed()
    {
        return this->GetAndClear(this->stop_algorithm);
    }

    bool ControlPanel::WasMuteAudioBtnPressed()
    {
        return this->GetAndClear(this->mute_audio);
    }

    bool ControlPanel::WasPlayAudioBtnPressed()
    {
        return this->GetAndClear(this->play_audio);
    }
}