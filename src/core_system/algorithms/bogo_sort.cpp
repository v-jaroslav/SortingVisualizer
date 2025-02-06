#include "core_system/algorithms/bogo_sort.hpp"
#include "core_system/algorithms/utilities.hpp"

#include <utility>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void BogoSort::Prepare() 
    {
        // The bogo sort requires us to do two phases, one is the shuffling, and then checking whether the array is sorted, therefore we need two fields used as indeces.
        // One that will point to element for which we will have to generate random index, and another that points to the element to check if its sorted in relation to its neighbors.
        this->i_shuffle = this->array.GetNumberOfVisibleElements() - 1;
        this->j_check   = 0;
    }

    void BogoSort::Step() 
    {
        if (i_shuffle >= 1) 
        {
            // For each element we will generate new random index in range [0, i_shuffle], and we will do this only in case i_shuffle >= 1.
            // Because if its zero, then we would generate new random index in range [0, 0], which means we wouldn't do anything.
            int new_index = GenerateRandomNumber(0, this->i_shuffle);
            std::swap(this->array[i_shuffle], this->array[new_index]);

            this->array[i_shuffle].SetFocus();
            this->array[new_index].SetFocus();

            // Update the i_shuffle, we go backwards from end to the front.
            --this->i_shuffle;
        }
        else if (this->j_check + 1 < this->array.GetNumberOfVisibleElements()) 
        {
            // If we have the neigbhor (j + 1) to the right, then great we have an element to compare the current one j-th one to. 
            this->array[j_check].SetFocus();
            this->array[j_check + 1].SetFocus();

            // If the j-th element is greater than (j + 1)th, then we have found invalid sorting order, therefore we have to reset the sort and start over. 
            // Otherwise move to the next consecutive pair to check if they are in valid order.
            if (this->array[j_check] > this->array[j_check + 1]) 
                this->Prepare();
            else
                ++this->j_check;
        }
        else
        {
            // If fisher yates is over, and if checking whether the array is sorted is also over and we did not reset the bogo sort, then the algorithm is done and we did sort the array.
            this->finished = true;
        }
    }
}
