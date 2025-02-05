#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_INSERTION_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_INSERTION_SORT_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class InsertionSort : public Algorithm
    {
    protected:
        void Prepare();
        
    public:
        void Step();
    };
}

#endif
