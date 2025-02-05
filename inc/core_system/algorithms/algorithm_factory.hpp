#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_FACTORY_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ALGORITHMS_FACTORY_HPP

#include <memory>

#include "core_system/array.hpp"
#include "core_system/algorithms/algorithm.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    class AlgorithmFactory
    {
    private:
        AlgorithmFactory() = default;

    public: 
        enum class AlgorithmType : int
        { 
            BUBBLE_SORT,
            SELECTION_SORT,
            INSERTION_SORT,
            COUNTING_SORT,
            MERGE_SORT,
            QUICK_SORT,
            BOGO_SORT
        };

        AlgorithmFactory(const AlgorithmFactory& factory) = delete; 
        AlgorithmFactory& operator = (const AlgorithmFactory& factory) = delete; 
        
        static AlgorithmFactory& GetInstance();
        
        std::shared_ptr<Algorithm> CreateAlgorithm(AlgorithmType type, Array& array);
    };
}

#endif