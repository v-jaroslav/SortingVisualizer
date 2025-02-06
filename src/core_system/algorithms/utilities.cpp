#include "core_system/algorithms/utilities.hpp"

#include <random>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    int GenerateRandomNumber(int min, int max)
    {
        // Prepare random generator once, so remember the mersenne twister in the static variable once.
        static std::random_device device;
        static std::mt19937 engine(device());
        
        // Generate random number from the range [min, max].
        std::uniform_int_distribution distribution(min, max);
        return distribution(engine);
    }
}