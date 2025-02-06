#include "core_system/algorithms/counting_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void CountingSort::Prepare() 
    {
        // For counting sort, we need a histogram, that will keep track how many times did each value appear, initially it shall be empty.
        for (int i = 0; i < this->array.GetNumberOfVisibleElements() + 1; ++i)
            this->histogram[i] = 0;

        // We also need "i" which will point to the next value in the array that we will want to record into histogram.
        // Also we need the "free", which will point to the next free slot in array at which we can place element, and "k", the next value to put at array[free].
        this->i = this->free = this->k = 0;
    }

    void CountingSort::Step() 
    {
        if (this->i < this->array.GetNumberOfVisibleElements()) 
        {
            // As long as we haven't recorded all the values of the array in the histogram, grab the array[i] and its value, use it as index and increment number at that index.
            // That way we "say" that this element "has appeared one more time". And focus that element, and move to the next element to record into the histogram.
            ++this->histogram[this->array[this->i].GetValue()];
            this->array[this->i].SetFocus();
            ++this->i;
        }
        else if (this->free < this->array.GetNumberOfVisibleElements()) 
        {
            // As long as there are free slots in the array, then we aren't done. In that case let us find the first value "k", that appears more than 0 times in histogram.
            while (this->histogram[this->k] == 0)
                ++this->k;

            // Store at the array[free] the value k, and let it be in "sorted" state.
            this->array[this->free].SetValue(this->k);
            this->array[this->free].SetSorted();

            // Decrement how many times did "k" appear in the histogram, and move to the next free slot.
            --this->histogram[this->k];
            ++this->free;
        }
        else 
        {
            // If we have finished altering the array, then the algorithm is complete.
            this->finished = true;
        }
    }
}