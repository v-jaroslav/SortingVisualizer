#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_MERGE_SORT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_MERGE_SORT_HPP

#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class MergeSort : public Algorithm
    {
    protected:
        int partition_size;
        int low;

        bool coppied;
        bool merge_done;

        int left_len, a;
        int left_tmp[Constants::Application::MAX_NUM_OF_ELEMS];

        int right_len, b;
        int right_tmp[Constants::Application::MAX_NUM_OF_ELEMS];

        int free;

        void Prepare();
        void Merge(int low, int mid, int high);
        
    public:
        using Algorithm::Algorithm;
        void Step();
    };
}

#endif



