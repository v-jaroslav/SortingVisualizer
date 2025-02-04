#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace Constants
{
    namespace Application
    {
        constexpr int MAX_NUM_OF_ELEMS = 100;    
        constexpr int MIN_NUM_OF_ELEMS = 10;    
    }

    namespace Window
    {
        constexpr int INITIAL_WIDTH  = 1000;
        constexpr int INITIAL_HEIGHT = 800;
        inline const char* TITLE     = "SortingVisualizer - By 0xTheVJ";
    } 
    
    namespace UserInterface::ControlPanel
    {
        constexpr float MARGIN_PX         = 10.0f;
        constexpr float PADDING_PX        = 10.0f;
        constexpr float STATUS_BAR_HEIGHT = 24.0f;
        constexpr float BUTTON_SIZE       = 18.0f;

        inline const char* STATUS_TITLE_OPEN   = "Control Panel (Open)";
        inline const char* STATUS_TITLE_CLOSED = "Control Panel (Closed)";

        inline const char* MIN_ELEMS_SLIDER          = "10";
        inline const char* MAX_ELEMS_SLIDER          = "100";
        inline const char* SLIDER_LABEL = "Number of elements:";
        
        inline const char* SORTING_ALGORITHM_LABEL = "Sorting algorithm: ";
        inline const char* ALGORITHM_OPTIONS = "Bogo Sort;Counting Sort;Bubble Sort;Selection Sort;Insertion Sort;Merge Sort;Quick Sort";
        
        inline const char* RUN_ALGORITHM_BTN  = "Run Algorithm";
        inline const char* STOP_ALGORITHM_BTN = "Stop Algorithm";
        inline const char* SHUFFLE_ELEMS_BTN  = "Shuffle Elements";
        inline const char* MUTE_AUDIO_BTN     = "Mute Audio";
        inline const char* PLAY_AUDIO_BTN     = "PLay Audio";
    }
}

#endif
