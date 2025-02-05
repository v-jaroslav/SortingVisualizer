#include "core_system/algorithms/merge_sort.hpp"

#include <algorithm>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void MergeSort::Prepare() {
        this->partition_size = 1;
        this->low = 0;

        this->merge_done = false;
        this->coppied = false;
    }

    void MergeSort::Merge(int low, int mid, int high) {
        if (!this->coppied) {
            this->left_len = mid - low + 1;
            this->right_len = high - mid;

            for (int i = 0; i < this->left_len; ++i) {
                this->left_tmp[i] = this->array[low + i].GetValue();
            }
            for (int i = 0; i < this->right_len; ++i) {
                this->right_tmp[i] = this->array[mid + 1 + i].GetValue();
            }

            this->coppied = true;

            this->a = this->b = 0;
            this->free = low;
        }

        if (a < left_len && b < right_len) {
            if (left_tmp[a] < right_tmp[b]) {
                this->array[free].SetValue(left_tmp[a++]);
                this->array[free++].SetFocus();
            }
            else {
                this->array[free].SetValue(right_tmp[b++]);
                this->array[free++].SetFocus();
            }
        }
        else {
            if (a < left_len) {
                this->array[free].SetValue(left_tmp[a++]);
                this->array[free++].SetFocus();
            }
            else if (b < right_len) {
                this->array[free].SetValue(right_tmp[b++]);
                this->array[free++].SetFocus();
            }
            else {
                this->merge_done = true;
            }
        }
    }

    void MergeSort::Step() {
        if (partition_size <= this->array.GetNumberOfVisibleElements() - 1) {
            if (low < this->array.GetNumberOfVisibleElements() - 1) {
                int mid = std::min(low + partition_size - 1, this->array.GetNumberOfVisibleElements() - 1);
                int high = std::min(low + 2 * partition_size - 1, this->array.GetNumberOfVisibleElements() - 1);
                this->Merge(low, mid, high);

                if (this->merge_done) {
                    // In case the merge is completed, move to the first element after the right partition.
                    low = low + 2 * partition_size;
                    this->merge_done = false;
                    this->coppied = false;
                }
            }
            else {
                // In case we went through all the partitions of the current size, we will go through partitions of the current size * 2.
                partition_size = 2 * partition_size;
                this->low = 0;
            }

            return;
        }

        // In case we went through all the partitions and merged them, then we are done.
        this->finished = true;
    }
}