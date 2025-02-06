#include "core_system/algorithms/counting_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void CountingSort::Prepare() {
        for (int i = 0; i < this->array.GetNumberOfVisibleElements() + 1; ++i) {
            this->histogram[i] = 0;
        }

        this->i = 0;
        this->free = 0;
        this->k = 0;
    }

    void CountingSort::Step() {
        if (this->i < this->array.GetNumberOfVisibleElements()) {
            ++this->histogram[this->array[this->i].GetValue()];
            this->array[this->i].SetFocus();
            ++this->i;
            return;
        }

        if (this->free < this->array.GetNumberOfVisibleElements()) {
            while (this->histogram[this->k] == 0) {
                ++this->k;
            }

            this->array[this->free].SetValue(this->k);
            this->array[this->free].SetSorted();

            --this->histogram[this->k];

            ++this->free;
            return;
        }

        this->finished = true;
    }
}