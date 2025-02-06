#include "core_system/algorithms/selection_sort.hpp"

#include <utility>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void SelectionSort::Prepare() 
    {
        // For the selection sort, we need an index "i" which points to the element for which we need to find a minimum to the right of it in range [j=(i + 1), n - 1].
        // We assume the [0, i - 1] part of array is sorted. And we need "min_i" to keep track of index of the smallest found element to the right of "i" currently same as "i".
        this->i = this->min_i = 0;
        this->j = 1;
    }

    void SelectionSort::Step() 
    {
        // If the element "i" has the right neighbor, then we can try to search for the smallest element to its right.
        if (this->i + 1 < this->array.GetNumberOfVisibleElements()) 
        {
            if (j < this->array.GetNumberOfVisibleElements()) 
            {
                // As long as we haven't gone through every element that is to the right of the i-th element, then let us check if j-th element is smaller than min_i-th one.
                if (this->array[j] < this->array[this->min_i]) 
                    this->min_i = j;
                this->array[j++].SetFocus();
            }
            else 
            {
                // If we did go through all elements to the right of i, check if min_i is not same as i, if not then we found smaller element than i-th one so swap them.
                if (this->i != this->min_i) 
                    std::swap(this->array[this->i], this->array[this->min_i]);
                this->array[this->i].SetSorted();

                // Move now to the next element (++i) for which we need to find a new minimum, and let that be our min_i for start.
                this->min_i = ++this->i;
                this->j = this->min_i + 1;
            }
        }
        else
        {
            // If the element does not have the element to its right, then this is the last element, and thus it must be sorted.
            this->array[this->array.GetNumberOfVisibleElements() - 1].SetSorted();
            this->finished = true;
        }
    }
}