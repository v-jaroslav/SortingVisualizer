#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_BOGO_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_BOGO_SORT_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class BogoSort : public Algorithm
    {
    protected:
        int i_shuffle, j_check;
        void Prepare();
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif


