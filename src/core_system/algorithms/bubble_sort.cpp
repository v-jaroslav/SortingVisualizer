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
        // Because we ignore the last round, in which we would "sort" a single element, that element won't be set to be "sorted", so we have to do it here manually.
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

        // If we finished one round of the bubble sort, move onto the next round from beginning (j=0).
        // And let the newly sorted element be "in sorted state", as its in correct position now.
        // The last (i + 1) elements are sorted in proper way, so we subtract (i + 1), we add 1 as i=0 is first round.
        // And yes we do want to start a new round if i=0 and j >= (n - 1) as (n-1)th element does not have the right neighbor.
        // And i mean remember, we are comparing after all j-th and (j + 1)th element, in that case we can't do that.
        if (this->j >= this->array.GetNumberOfVisibleElements() - (i + 1)) 
        {
            this->array[this->array.GetNumberOfVisibleElements() - (i + 1)].SetSorted();
            this->j = 0;
            ++this->i;
        }
    }
}