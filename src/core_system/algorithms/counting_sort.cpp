#include "core_system/algorithms/counting_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void CountingSort::Prepare() 
    {
        // For counting sort, we need a histogram, that will keep track how many times did each value appear, which will be stored at histogram[value].
        // Initially it shall be empty, as we haven't recorded how many times does any value appear in the array.
        for (int i = 0; i < this->array.GetNumberOfVisibleElements() + 1; ++i)
            this->histogram[i] = 0;

        // Next, we need "i" which will point to the next value in the array that we will want to record into histogram.
        // We also need the "free", which will point to the next free slot in array at which we can place element.
        // We need "k" which will tell us the next value to put at the array[free]. All of them are initially 0.
        this->i = this->free = this->k = 0;
    }

    void CountingSort::Step() 
    {
        if (this->i < this->array.GetNumberOfVisibleElements()) 
        {
            // As long as we haven't recorded all the values of the array in the histogram.
            // Then grab this->array[i], and grab its value, and use that value as index of histogram, and increment number at that index.
            // That way we "say" that this element "has appeared one more time".
            ++this->histogram[this->array[this->i].GetValue()];
            
            // And also set the focus on the i-th element. And move on to the next element to record it into the histogram.
            this->array[this->i].SetFocus();
            ++this->i;
        }
        else if (this->free < this->array.GetNumberOfVisibleElements()) 
        {
            // If we are done with recording the elements in the histogram, it's time to alter the array.
            // As long as there are free slots in the array, then we aren't done. In that case let us find the first value "k".
            // That does not appear 0 times, but more than 0 times, which means we can add it to the array.
            while (this->histogram[this->k] == 0)
                ++this->k;

            // So store at the array[free] the value k, and let it be "sorted".
            this->array[this->free].SetValue(this->k);
            this->array[this->free].SetSorted();

            // Decrement how many times did "k" appear in the histogram, and move to the next free slot.
            --this->histogram[this->k];
            ++this->free;
        }
        else 
        {
            // If we have finished alterint the array, then the algorithm is complete.
            this->finished = true;
        }
    }
}