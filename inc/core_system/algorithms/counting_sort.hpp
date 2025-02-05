#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_COUNTING_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_COUNTING_SORT_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class CountingSort : public Algorithm
    {
    protected:
        int histogram[Constants::Application::MAX_NUM_OF_ELEMS + 1];
        int i, free, k;
        void Prepare();
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif


