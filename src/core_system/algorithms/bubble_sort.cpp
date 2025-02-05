#include "core_system/algorithms/bubble_sort.hpp"

#include <utility>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void BubbleSort::Prepare()
    {
        this->i = this->j = 0;
    }

    void BubbleSort::Step()
    {
        if (this->i < this->array.GetNumberOfVisibleElements() - 1) {
            if (this->j < this->array.GetNumberOfVisibleElements() - 1 - i) {
                // When comparing two elements, set their color to red.
                this->array[j].SetFocus();
                this->array[j + 1].SetFocus();

                // If you found the two elements that are in the wrong order, swap them.
                if (this->array[j] > this->array[j + 1])
                    std::swap(this->array[j], this->array[j + 1]);

                // Move to the next element.
                ++this->j;

                // If we finished one round of the bubble sort, move onto the next. And color the newly sorted element with blue, as its in correct position.
                if (this->j >= this->array.GetNumberOfVisibleElements() - 1 - i) {
                    this->array[this->array.GetNumberOfVisibleElements() - 1 - i].SetFill(BLUE);
                    this->j = 0;
                    ++this->i;
                }
            }

            return;
        }

        // If we have sorted n - 1 elements out of n elements, then we have sorted all the n elements.
        // Therefore the algorithm above won't color the first element blue, so we will do it manually here.
        this->array[0].SetFill(BLUE);

        // If we went through all the rounds, set that we finished sorting to true.
        this->finished = true;
    }
}