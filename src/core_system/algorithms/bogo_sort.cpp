#include "core_system/algorithms/bogo_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void BogoSort::Prepare() {
        this->i_shuffle = this->array.GetNumberOfVisibleElements() - 1;
        this->j_check = 0;
    }

    void BogoSort::Step() {
        if (i_shuffle >= 1) {
            int new_index = GetRandomValue(0, this->i_shuffle);

            Element temp = this->array[i_shuffle];
            this->array[i_shuffle] = this->array[new_index];
            this->array[new_index] = temp;

            this->array[i_shuffle].SetFocus();
            this->array[new_index].SetFocus();

            --this->i_shuffle;
            return;
        }
        else if (this->j_check < this->array.GetNumberOfVisibleElements() - 1) {
            this->array[j_check].SetFocus();
            this->array[j_check + 1].SetFocus();

            if (this->array[j_check] > this->array[j_check + 1]) {
                this->Prepare();
            }
            else {
                ++this->j_check;
            }

            return;
        }

        this->finished = true;
    }

}