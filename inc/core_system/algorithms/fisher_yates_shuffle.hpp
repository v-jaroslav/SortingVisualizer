#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_FISHER_YATES_SHUFFLE_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_FISHER_YATES_SHUFFLE_HPP

#include "core_system/algorithms/algorithm.hpp"

#include <random>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class FisherYatesShuffle : public Algorithm
    {
    protected:
        int swap_next;

        static int GenerateRandomNumber(int min, int max);

        void Prepare();
        
    public:
        // Inherit the constructor from Algorithm class.
        using Algorithm::Algorithm;

        void Step();
    };
}

#endif