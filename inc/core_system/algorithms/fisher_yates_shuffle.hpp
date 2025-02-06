#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_FISHER_YATES_SHUFFLE_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_FISHER_YATES_SHUFFLE_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class FisherYatesShuffle : public Algorithm
    {
    protected:
        int swap_next;

        void Prepare();
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif