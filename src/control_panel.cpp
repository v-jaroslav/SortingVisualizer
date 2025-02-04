#include "control_panel.hpp"
#include "constants.hpp"

#include <raygui.h>

namespace UserInterface
{
    float GetScaledWidth()
    {
        return GetRenderWidth() / GetWindowScaleDPI().x;
    }

    float GetScaledHeight()
    {
        return GetRenderHeight() / GetWindowScaleDPI().y;
    }

    void ControlPanel::Draw()
    {
        using Constants::UserInterface::MARGIN_PX;
        using Constants::UserInterface::BUTTON_SIZE;
        using Constants::UserInterface::STATUS_BAR_HEIGHT;
        using Constants::UserInterface::CONTROL_PANEL_OPEN;
        using Constants::UserInterface::CONTROL_PANEL_CLOSED;

        if (this->show_panel)
        {
            // Render the GuiWindowBox, and if the close button was pressed, then set the flag show_panel to be false, if it wasnt pressed, then we can freely render the controls in the panel.
            Rectangle window_box_bounds { MARGIN_PX, MARGIN_PX, GetScaledWidth() - 2*MARGIN_PX, this->panel_height };
            if (GuiWindowBox(window_box_bounds, CONTROL_PANEL_OPEN))
                this->show_panel = false;
            else
                this->DrawControls(); 
        }
        else
        {
            // If the control panel is supposed to be hidden, just draw it's status bar.
            Rectangle status_bar_bounds { MARGIN_PX, MARGIN_PX, GetScaledWidth() - 2*MARGIN_PX, STATUS_BAR_HEIGHT };
            GuiStatusBar(status_bar_bounds, CONTROL_PANEL_CLOSED);
            
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

    void ControlPanel::DrawControls()
    {
        this->panel_height = 200;
    }
}