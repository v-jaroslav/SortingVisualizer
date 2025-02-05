#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_QUICK_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_QUICK_SORT_HPP

#include <stack>
#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class QuickSort : public Algorithm
    {
    protected:
        std::stack<std::pair<int, int>> ranges;
        int low, high;

        int left, right;
        bool valid_ptrs;
        bool left_checked;
        bool right_checked;

        Element pivot;
        int pivot_index;
        bool pivot_set;

        bool done_partitioning;

        void Partition();

        void Prepare();
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif



