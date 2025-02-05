#include "core_system/algorithms/fisher_yates_shuffle.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    int FisherYatesShuffle::GenerateRandomNumber(int min, int max)
    {
        static std::random_device device;
        static std::mt19937 engine(device());        
        std::uniform_int_distribution distribution(min, max);
        return distribution(engine);
    }

    void FisherYatesShuffle::Prepare()
    {
        this->swap_next = this->array.GetNumberOfVisibleElements() - 1;        
    }

    void FisherYatesShuffle::Step()
    {
        if (this->swap_next == 0)
        {
            this->finished = true;
            return;
        }
        
        int new_index = GenerateRandomNumber(0, this->swap_next); 
        std::swap(this->array[this->swap_next], this->array[new_index]);
        this->array[this->swap_next].Focus(RED);
        this->array[new_index].Focus(RED);
        --this->swap_next;
    }
}