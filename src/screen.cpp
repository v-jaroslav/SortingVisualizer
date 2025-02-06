#include "screen.hpp"

#include <raylib.h>

namespace SortingVisualizer::UserInterface
{
    float GetScaledWidth()
    {
        // Read the HIGHDPI scale factor only once and store it in a static variable, as it is costly operation as you have to ask OS for that information.
        // It is not expected for user to change HIGHDPI settings randomly, if he does, he may just restart the app in order to apply them.
        static float x_scale = GetWindowScaleDPI().x;
        return GetRenderWidth() / x_scale;
    }

    float GetScaledHeight()
    {
        static float y_scale = GetWindowScaleDPI().y;
        return GetRenderHeight() / y_scale;
    }
}