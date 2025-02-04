#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace Constants
{
    namespace Window
    {
        constexpr int INITIAL_WIDTH  = 1000;
        constexpr int INITIAL_HEIGHT = 800;
        inline const char* TITLE     = "SortingVisualizer - By 0xTheVJ";
    } 
    
    namespace UserInterface
    {
        constexpr float MARGIN_PX         = 10.0f;
        constexpr float STATUS_BAR_HEIGHT = 24.0f;
        constexpr float BUTTON_SIZE       = 18.0f;

        inline const char* CONTROL_PANEL_OPEN   = "Control Panel (Open)";
        inline const char* CONTROL_PANEL_CLOSED = "Control Panel (Closed)";
    }
}

#endif
