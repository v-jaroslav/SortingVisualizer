#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_ALGORITHM_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_ALGORITHM_HPP

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
        
        virtual void Step() = 0;
        bool IsDone() const;
        void Reset();
    };
}

#endif