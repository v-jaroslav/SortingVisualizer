#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_QUICK_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_QUICK_SORT_HPP

#include <stack>
#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class QuickSort : public Algorithm
    {
    protected:
        std::stack<std::pair<int, int>> ranges;
        int low, high;

        bool valid_ptrs;

        int left_ptr;
        bool move_left_ptr_done;
        
        int right_ptr;
        bool move_right_ptr_done;

        Element pivot;
        int pivot_index;

        bool initialized_partitioning;
        bool done_partitioning;

        void Partition();
        void Prepare();
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif



