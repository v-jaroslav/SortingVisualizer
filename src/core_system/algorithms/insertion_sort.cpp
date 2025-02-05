#include "core_system/algorithms/insertion_sort.hpp"

#include <utility>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void InsertionSort::Prepare()
    {
        // Insertion sort is basically card sort, we start from the second element, so use the 2nd index as initial index.
        this->i = this->j = 1;
    }

    void InsertionSort::Step()
    {
        // If the next element to insert into already sorted area is the one that is out of bounds, then insertion sort has finished.
        if (this->i >= this->array.GetNumberOfVisibleElements())
        {
            this->finished = true;
            return;
        }
        
        if (this->j - 1 >= 0 && this->array[this->j - 1] > this->array[this->j])
        {
            // If we do have a previous element, and if previous element is greater than current one.
            // Then swap the two elements, and focus them both as a graphical feedback.
            std::swap(this->array[this->j - 1], this->array[this->j]);
            this->array[this->j - 1].SetFocus();
            this->array[this->j].SetFocus();
            
            // After that, lets check if this element is in sorted position compared to previous element now that we have swapped it.
            --this->j;
        }
        else 
        {
            // Otherwise, we have successfully inserted i-th element to the sorted portion, now its time to insert the next (i + 1)th element to that sorted portion.
            this->j = ++this->i;
        }
    }
}