#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_BOGO_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_BOGO_SORT_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class BogoSort : public Algorithm
    {
    protected:
        int i_shuffle, j_check;
        void Prepare();
        
    public:
        // Inherit constructor from Algorithm super-class.
        using Algorithm::Algorithm;

        void Step();
    };
}

#endif
