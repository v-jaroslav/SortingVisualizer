#ifndef SORTING_VISUALIZER_CONSTANTS_HPP
#define SORTING_VISUALIZER_CONSTANTS_HPP

namespace SortingVisualizer::Constants
{
    namespace Application
    {
        constexpr int MAX_NUM_OF_ELEMS = 500;
        constexpr int MIN_NUM_OF_ELEMS = 3;
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

        // These values were taken from raygui.h, but raygui.h doesn't provide any "public" constants for these.
        constexpr float STATUS_BAR_HEIGHT = 24.0f;
        constexpr float BUTTON_SIZE       = 18.0f;

        inline const char* STATUS_BAR_TITLE_OPEN   = "Control Panel (Open)";
        inline const char* STATUS_BAR_TITLE_CLOSED = "Control Panel (Closed)";

        inline const char* MIN_ELEMS_SLIDER   = "3";
        inline const char* MAX_ELEMS_SLIDER   = "500";
        inline const char* ELEMS_SLIDER_LABEL = "Number of elements:";
        
        inline const char* SORTING_ALGORITHM_LABEL = "Sorting algorithm:";
        inline const char* ALGORITHM_OPTIONS = "Bubble Sort;Selection Sort;Insertion Sort;Counting Sort;Merge Sort;Quick Sort;Bogo Sort";
        
        inline const char* RUN_ALGORITHM_BTN  = "Run Algorithm";
        inline const char* STOP_ALGORITHM_BTN = "Stop Algorithm";
        inline const char* SHUFFLE_ELEMS_BTN  = "Shuffle Elements";
        inline const char* MUTE_AUDIO_BTN     = "Mute Audio";
        inline const char* PLAY_AUDIO_BTN     = "Play Audio";
    }
    
    namespace Audio
    {
        // Maximum frequency that is played when we focus on element with highest visible value.
        constexpr int MAX_FREQUENCY = 1000;
        
        // Maximum amplitude will be 32k, since we have 16 bit sample size.
        constexpr int SAMPLE_SIZE   = 16;
        constexpr int AMPLITUDE     = 32000;

        // How many samples per second will be played.
        constexpr int SAMPLING_RATE = 44100;
        
        // Buffer size in bytes, in which we will have amplitudes stored.
        constexpr int BUFFER_SIZE   = 4096;
        
        // How many audio channels do we have.
        constexpr int N_CHANNELS    = 1;
    }
}

#endif
