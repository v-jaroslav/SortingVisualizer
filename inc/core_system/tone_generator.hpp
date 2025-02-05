
#ifndef SORTING_VISUALIZER_CORE_SYSTEM_TONE_GENERATOR_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_TONE_GENERATOR_HPP

#include <raylib.h>

namespace SortingVisualizer::CoreSystem
{
    class ToneGenerator {
    private:
        static float frequency;
        static float tanhIdx;

        static AudioStream stream;

        static void wave_generator_callback(void *buffer, unsigned int frames);

    public:
        static void Initialize();

        static float GetFrequency();
        static void SetFrequency(float frequency);

        static void Play();
        static void Stop();

        static void Dispose();
    };
}

#endif