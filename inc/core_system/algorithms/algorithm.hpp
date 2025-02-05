#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_ALGORITHM_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_SORTING_ALGORITHM_HPP

#include "core_system/array.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class Algorithm
    {
    protected:
        Array& array; 
        bool finished;
        
        virtual void Prepare() = 0;
        
    public:
        Algorithm(Array& a);
        
        bool IsDone() const;
        virtual void Step() = 0;
        void Reset();
    };
}

#endif