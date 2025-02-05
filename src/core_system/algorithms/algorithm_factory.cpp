#include "core_system/algorithms/algorithm_factory.hpp"

#include "core_system/algorithms/insertion_sort.hpp"
#include "core_system/algorithms/bubble_sort.hpp"
#include "core_system/algorithms/bogo_sort.hpp"
#include "core_system/algorithms/counting_sort.hpp"
#include "core_system/algorithms/selection_sort.hpp"
#include "core_system/algorithms/merge_sort.hpp"
#include "core_system/algorithms/quick_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    AlgorithmFactory& AlgorithmFactory::GetInstance()
    {
        // Create a single static instance, and return it whenever asked.
        static AlgorithmFactory instance;
        return instance;
    }
        
    std::shared_ptr<Algorithm> AlgorithmFactory::CreateAlgorithm(AlgorithmType type, Array& array)
    {
        switch(type)
        {
            case AlgorithmType::BUBBLE_SORT:
                return std::make_shared<BubbleSort>(array);

            case AlgorithmType::INSERTION_SORT:
                return std::make_shared<InsertionSort>(array);
                
            case AlgorithmType::BOGO_SORT:
                return std::make_shared<BogoSort>(array);

            case AlgorithmType::COUNTING_SORT:
                return std::make_shared<CountingSort>(array);

            case AlgorithmType::SELECTION_SORT:
                return std::make_shared<SelectionSort>(array);

            case AlgorithmType::MERGE_SORT:
                return std::make_shared<MergeSort>(array);

            case AlgorithmType::QUICK_SORT:
                return std::make_shared<QuickSort>(array);
        } 
    }
}