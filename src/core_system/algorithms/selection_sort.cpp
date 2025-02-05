#include "core_system/algorithms/selection_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void SelectionSort::Prepare() {
        this->i = 0;
        this->j = 1;
        this->min_i = 0;
    }

    void SelectionSort::Step() {
        if (this->i < this->array.GetNumberOfVisibleElements() - 1) {
            if (j < this->array.GetNumberOfVisibleElements()) {
                if (this->array[j] < this->array[this->min_i]) {
                    this->min_i = j;
                }

                this->array[j++].SetFocus();
            }
            else {
                if (this->i != this->min_i) {
                    Element temp = this->array[this->i];
                    this->array[this->i] = this->array[this->min_i];
                    this->array[this->min_i] = temp;
                }

                this->array[this->i].SetFill(BLUE);

                ++this->i;
                this->min_i = this->i;
                this->j = this->min_i + 1;
            }

            return;
        }

         this->array[this->array.GetNumberOfVisibleElements() - 1].SetFill(BLUE);

        this->finished = true;
    }
}