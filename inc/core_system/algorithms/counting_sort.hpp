#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_COUNTING_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_COUNTING_SORT_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class CountingSort : public Algorithm
    {
    protected:
        // We know that we will have at most MAX_NUM_OF_ELEMS numbers, so let us have a histogram of size (MAX_NUM_OF_ELEMS + 1), so that we can use MAX_NUM_OF_ELEMS as index as well.
        int histogram[Constants::Application::MAX_NUM_OF_ELEMS + 1];
        int i, free, k;

        void Prepare();
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif


