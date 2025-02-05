#include "core_system/algorithms/fisher_yates_shuffle.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    int FisherYatesShuffle::GenerateRandomNumber(int min, int max)
    {
        // Prepare random generator once, so remember the mersenne twister in the static variable once.
        static std::random_device device;
        static std::mt19937 engine(device());        
        
        // Generate random number from range [min, max].
        std::uniform_int_distribution distribution(min, max);
        return distribution(engine);
    }

    void FisherYatesShuffle::Prepare()
    {
        // The fisher yates shuffle starts from the last element, so let the next index to swap with other random index be the last index.
        this->swap_next = this->array.GetNumberOfVisibleElements() - 1;        
    }

    void FisherYatesShuffle::Step()
    {
        if (this->swap_next == 0)
        {
            // If we have reached the first element, then the fisher yates algorithm is complete.
            this->finished = true;
            return;
        }
        
        // Generate random index in range of [0, swap_next], thats the new index of the element at index swap_next, so swap the two elements at the current and new index.
        int new_index = GenerateRandomNumber(0, this->swap_next); 
        std::swap(this->array[this->swap_next], this->array[new_index]);

        // Focus the newly swapped elements as a graphical feedback to the user.
        this->array[this->swap_next].SetFocus();
        this->array[new_index].SetFocus();

        // Move to the next element downwards, the next one for which we need to generate new random index.
        --this->swap_next;
    }
}