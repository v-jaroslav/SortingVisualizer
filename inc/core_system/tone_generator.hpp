
#ifndef SORTING_VISUALIZER_CORE_SYSTEM_TONE_GENERATOR_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_TONE_GENERATOR_HPP

#include <raylib.h>

namespace SortingVisualizer::CoreSystem
{
    class ArrayToneGenerator {
    private:
        static float wave_idx;
        static float frequency;
        static float division_factor;

        static AudioStream stream;

        static void wave_generator_callback(void *buffer, unsigned int frames);

    public:
        static void Initialize();

        static void SetFrequency(float array_value);
        static void SetDivisionFactor(float value);

        static void Play();
        static void Stop();

        static void Dispose();
    };
}

#endif