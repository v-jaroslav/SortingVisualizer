#ifndef SORTING_VISUALIZER_CONSTANTS_HPP
#define SORTING_VISUALIZER_CONSTANTS_HPP

namespace SortingVisualizer::Constants
{
    namespace Application
    {
        constexpr int MAX_NUM_OF_ELEMS = 500;
        constexpr int MIN_NUM_OF_ELEMS = 10;
        constexpr float DELTA_TIME     = 1.0f / 60.0f;
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
        inline const char* MAX_ELEMS_SLIDER          = "500";
        inline const char* SLIDER_LABEL = "Number of elements:";
        
        inline const char* SORTING_ALGORITHM_LABEL = "Sorting algorithm: ";
        inline const char* ALGORITHM_OPTIONS = "Bubble Sort;Selection Sort;Insertion Sort;Counting Sort;Merge Sort;Quick Sort;Boggo Sort";
        
        inline const char* RUN_ALGORITHM_BTN  = "Run Algorithm";
        inline const char* STOP_ALGORITHM_BTN = "Stop Algorithm";
        inline const char* SHUFFLE_ELEMS_BTN  = "Shuffle Elements";
        inline const char* MUTE_AUDIO_BTN     = "Mute Audio";
        inline const char* PLAY_AUDIO_BTN     = "PLay Audio";
    }
    
    namespace Audio
    {
        constexpr int MAX_FREQUENCY = 1000;
        constexpr int AMPLITUDE = 32000;
        constexpr int SAMPLING_RATE = 44100;
        constexpr int SAMPLE_SIZE = 16;
        constexpr int BUFFER_SIZE = 4096;
    }
}

#endif
