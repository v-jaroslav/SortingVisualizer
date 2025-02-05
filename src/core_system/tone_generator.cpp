#include "core_system/tone_generator.hpp"
#include "constants.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace SortingVisualizer::CoreSystem
{
    float ToneGenerator::frequency = 440.0f;
    float ToneGenerator::tanhIdx = 0.0f;
    AudioStream ToneGenerator::stream;

    void ToneGenerator::wave_generator_callback(void *buffer, unsigned int frames) {
        // We are using 16-bit sample size, therefore we will use short*.
        short *data = (short*)buffer;

        for (unsigned int i = 0; i < frames; ++i) {
            // Calculate the frequency of the i-th sample.
            data[i] = (short)(Constants::Audio::AMPLITUDE * tanh(2 * M_PI * tanhIdx));

            // Increment the tanhIdx, if there is no change in the wave there is no sound.
            tanhIdx += frequency / Constants::Audio::SAMPLING_RATE;
            if (tanhIdx > 1.0f) {
                tanhIdx -= 1.0f;
            }
        }
    }

    void ToneGenerator::Initialize() {
        static bool is_initialized = false;

        if (!is_initialized) {
            // Initialize the audio device and set the size of the audio buffer that will contain the frequencies of each sample.
            InitAudioDevice();
            SetAudioStreamBufferSizeDefault(Constants::Audio::BUFFER_SIZE);

            // Create audio stream object with the sample rate of 44100, the sample size of 16 bits, for 1 single channel.
            stream = LoadAudioStream(Constants::Audio::SAMPLING_RATE, Constants::Audio::SAMPLE_SIZE, 1);
            SetAudioStreamCallback(stream, wave_generator_callback);

            // Remember that we did initalize the audio.
            is_initialized = true;
        }
    }

    float ToneGenerator::GetFrequency() {
        return frequency;
    }

    void ToneGenerator::SetFrequency(float frequency) {
        ToneGenerator::frequency = frequency;
    }

    void ToneGenerator::Play() {
        PlayAudioStream(stream);
    }

    void ToneGenerator::Stop() {
        StopAudioStream(stream);
    }

    void ToneGenerator::Dispose() {
        UnloadAudioStream(stream);
    }
}