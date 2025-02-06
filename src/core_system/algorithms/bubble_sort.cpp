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
        // This is true because in every round one element gets sorted to its proper position, it "bubbles up" to its position.
        // As we ignore the last round, in which we would sort a single element, that element won't be colored blue, so we have to do it here.
        if (this->i >= this->array.GetNumberOfVisibleElements() - 1)
        {
            this->finished = true;
            this->array[0].SetSorted();
            return;
        }

        // When comparing two elements, set their color to red.
        this->array[j].SetFocus();
        this->array[j + 1].SetFocus();

        // If you found the two elements that are in the wrong order, swap them.
        if (this->array[j] > this->array[j + 1])
            std::swap(this->array[j], this->array[j + 1]);

        // Move to the next element.
        ++this->j;

        // If we finished one round of the bubble sort, move onto the next round. And color the newly sorted element with blue, as its in correct position.
        // The last i elements are sorted in proper way, and thus there is no need to compare the last i elements.
        if (this->j >= this->array.GetNumberOfVisibleElements() - 1 - i) {
            this->array[this->array.GetNumberOfVisibleElements() - 1 - i].SetSorted();
            this->j = 0;
            ++this->i;
        }
    }
}