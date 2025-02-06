#include "core_system/tone_generator.hpp"
#include "constants.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

namespace SortingVisualizer::CoreSystem
{
    // Just definitions for static declarations that we have in our header file.
    AudioStream ArrayToneGenerator::stream;
    float ArrayToneGenerator::division_factor = Constants::Application::MIN_NUM_OF_ELEMS;
    float ArrayToneGenerator::frequency;
    float ArrayToneGenerator::wave_idx;

    void ArrayToneGenerator::wave_generator_callback(void *buffer, unsigned int frames) {
        // We are given a pointer to a buffer of the size that we have set initially. The data type of pointer is short as its of 16 bits which is same as the sample size.
        short *data = (short*)buffer;
        
        // When it comes to single audio channel, 1 frame would be 1 sample as that 1 sample is being played by both audio channels.
        // If we had two audio channels, 1 frame would have 2 samples, as two different samples would have to be played at the same time.
        // Therefore, we have BUFFER_SIZE / (CHANNELS * (SAMPLE_SIZE / 8)) number of frames, for each sample we have to set the amplitude.
        // If we used two channels, we would have to set the sample amplitude data[frame_idx * 2 + 0] for left and data[frame_idx * 2 + 1] for right channel.
        // Here mono channel is used, as both channels would have the same samples anyways, this way we are saving on processing power, and we have more frames for the same buffer.
    
        for (int i = 0; i < frames; ++i)
        {
            data[i]  = (short) (Constants::Audio::AMPLITUDE * sin(2 * M_PI * wave_idx));
            
            // As the frequency we have, is related to the number of times the wave should change in one second (go from +1.0 to -1.0).
            // And as we really want to spread that over one second since thats what the frequency tells us, then we have to divide that frequency by SAMPLING_RATE.
            // Since that is how many samples will be played in one second, and each sample in that one second then should differ by frequency / SAMPLING_RATE.
            wave_idx += ArrayToneGenerator::frequency / Constants::Audio::SAMPLING_RATE;
            
            // After we go through one full cycle, reset the wave_idx to be 0.0f, as sin(2*PI*1) is same as sin(2*PI*0).
            if (wave_idx >= 1.0f)
                wave_idx = 0.0f;
        }
    }

    void ArrayToneGenerator::Initialize() 
    {
        // Initialize the audio device, and set the audio stream buffer to be of size BUFFER_SIZE bytes.
        InitAudioDevice();
        SetAudioStreamBufferSizeDefault(Constants::Audio::BUFFER_SIZE);

        // Create an audio stream, that has sampling rate of SAMPLING_RATE hertz (how many samples per second are played), make sure the size of sample in bits is SAMPLE_SIZE, and set the number of channels.
        ArrayToneGenerator::stream = LoadAudioStream(Constants::Audio::SAMPLING_RATE, Constants::Audio::SAMPLE_SIZE, Constants::Audio::N_CHANNELS);
        
        // The audio stream that we just created will be controlled by the callback function that will generate the audio samples.
        SetAudioStreamCallback(ArrayToneGenerator::stream, ArrayToneGenerator::wave_generator_callback);
    }

    void ArrayToneGenerator::SetFrequency(float value) 
    {
        // The value that is passed is value from array, divide it with division factor to get %, then multiply it with maximum frequency we can play, that is our frequency to play.
        ArrayToneGenerator::frequency = (value / ArrayToneGenerator::division_factor) * Constants::Audio::MAX_FREQUENCY;
    }

    void ArrayToneGenerator::SetDivisionFactor(float value)
    {
        // Set the divsiion factor, that will control how the frequency that will be used will be calculated.
        ArrayToneGenerator::division_factor = value; 
    }

    void ArrayToneGenerator::Play() 
    {
        PlayAudioStream(ArrayToneGenerator::stream);
    }

    void ArrayToneGenerator::Stop() 
    {
        StopAudioStream(ArrayToneGenerator::stream);
    }

    void ArrayToneGenerator::Dispose() 
    {
        UnloadAudioStream(ArrayToneGenerator::stream);
        CloseAudioDevice();
    }
}