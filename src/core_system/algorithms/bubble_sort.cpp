#include "core_system/algorithms/bubble_sort.hpp"

#include <utility>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void BubbleSort::Prepare()
    {
        // i keeps track of how many rounds we need to go through, j keeps track of which elements we need to compare.
        this->i = this->j = 0;
    }

    void BubbleSort::Step()
    {
        // If we have gone through n - 1 rounds, then all elements must be sorted, therefore we are done.
        // This is true because in every round one element gets sorted to its proper position, it "bubbles up" to its position, if we have (n - 1) elements sorted, we really have n elements sorted!
        // Because we ignored the last round, in which we would "sort" a single element, that element won't be set to be "sorted", so we have to do it here manually.
        if (this->i >= this->array.GetNumberOfVisibleElements() - 1)
        {
            this->finished = true;
            this->array[0].SetSorted();
            return;
        }

        // When comparing two elements, let them be focused.
        this->array[j].SetFocus();
        this->array[j + 1].SetFocus();

        // If you found the two elements that are in the wrong order, swap them.
        if (this->array[j] > this->array[j + 1])
            std::swap(this->array[j], this->array[j + 1]);

        // Move to the next element.
        ++this->j;

        // If we finished one round of the bubble sort, move onto the next round from the beginning (j=0), and increment the i as we are starting the new round.
        // And let the newly sorted element be "in sorted state", as its in correct position now.
        // That newly sorted element is at index ((n - 1) - i), and if j is now at that index, then we are done. 
        // As that element is sorted for sure, no need to compare it further, in every bubble sort round the greatest "non-sorted" value gets sorted in its proper position.
        if (this->j >= (this->array.GetNumberOfVisibleElements() - 1) - i) 
        {
            this->array[(this->array.GetNumberOfVisibleElements() - 1) - i].SetSorted();
            this->j = 0;
            ++this->i;
        }
    }
}