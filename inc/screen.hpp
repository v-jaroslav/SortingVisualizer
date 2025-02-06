#ifndef SORTING_VISUALIZER_USER_INTERFACE_SCREEN_HPP
#define SORTING_VISUALIZER_USER_INTERFACE_SCREEN_HPP

namespace SortingVisualizer::UserInterface
{
    // We have these functions here, because raylib doesn't work properly on HighDPI screens.
    float GetScaledWidth();
    float GetScaledHeight();
}

#endif