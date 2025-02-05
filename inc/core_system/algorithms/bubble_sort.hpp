#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_BUBBLE_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_BUBBLE_SORT_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class BubbleSort : public Algorithm
    {
    protected:
        int i, j;
        void Prepare();
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif

