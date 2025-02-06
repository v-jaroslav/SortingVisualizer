#include "core_system/algorithms/selection_sort.hpp"

#include <utility>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void SelectionSort::Prepare() 
    {
        // For selection sort, we need three things, an index "i" which points to element for which we need to find a minimum.
        // Where the minimum we are looking for is the on to the right of "i" starting from index "j", which is always initially +1 compared to "i".
        // We assume the [0, i - 1] part of array is sorted. And we also need "min_i" to keep track of index of the smallest found element to the right of "i" currently same as "i".
        this->i = this->min_i = 0;
        this->j = 1;
    }

    void SelectionSort::Step() 
    {
        // If the element "i" has the right neighbor, then we can try to search for the smallest element to its right, otherwise we cant.
        if (this->i + 1 < this->array.GetNumberOfVisibleElements()) 
        {
            if (j < this->array.GetNumberOfVisibleElements()) 
            {
                // As long as we haven't gone through every element that is to the right of i-th element.
                // Then let us compare j-th and min_i-th element, if j-th one is smaller, remember that in min_i.
                if (this->array[j] < this->array[this->min_i]) 
                    this->min_i = j;
                
                // And as you go through those element that are to the right of i-th, focus them.
                this->array[j++].SetFocus();
            }
            else 
            {
                // If we did go through all elements to the right of i, check if min_i is not same as i.
                // If its not same, we found smaller element than i-th, so swap them.
                if (this->i != this->min_i) 
                    std::swap(this->array[this->i], this->array[this->min_i]);
                
                // Now i-th element is for sure sorted, so let that be its state now.
                this->array[this->i].SetSorted();

                // Move now to the next element (++i) for which we need to find a new minimum, and let that be our min_i for start.
                // And of course we always start looking for elements to the right of i starting from (i + 1) so let that value be set to j.
                this->min_i = ++this->i;
                this->j = this->min_i + 1;
            }
        }
        else
        {
            // If the element does not have the element to its right, then this is the last element, and thus it must be sorted.
            // So let its state be sorted, and this is where the algorithm actually ends.
            this->array[this->array.GetNumberOfVisibleElements() - 1].SetSorted();
            this->finished = true;
        }
    }
}