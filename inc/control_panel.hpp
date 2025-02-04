#ifndef USER_INTERFACE_CONTROL_PANEL_HPP
#define USER_INTERFACE_CONTROL_PANEL_HPP

namespace UserInterface
{
    // We have these functions here, because raygui.h header library doesn't work properly on HighDPI screens.
    float GetScaledWidth();
    float GetScaledHeight();

    class ControlPanel
    {
    private:
        float panel_height;
        bool show_panel = true;

        void DrawControls();

    public:
        void Draw();
    };
}

#endif