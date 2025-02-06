#include "core_system/algorithms/quick_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void QuickSort::Prepare() 
    {
        this->ranges = std::stack<std::pair<int, int>>();
        this->ranges.push({ 0, this->array.GetNumberOfVisibleElements() - 1 });

        this->done_partitioning = true;
        this->pivot_set = false;
        this->left_checked = false;
        this->right_checked = false;
    }

    void QuickSort::Partition() 
    {
        if (!this->pivot_set)  
        {
            this->pivot = this->array[this->low];
            this->pivot_set = true;

            this->left = this->low;
            this->right = this->high;

            this->left_checked = false;
            this->right_checked = false;
            this->valid_ptrs = false;
        }

        if (this->left < this->right)
            this->valid_ptrs = true;

        if (this->valid_ptrs) 
        {
            if (!this->left_checked) 
            {
                if (this->array[left] <= pivot && left < right) 
                {
                    this->array[left].SetFocus();
                    ++this->left;
                    return;
                }
                else 
                {
                    this->left_checked = true;
                }
            }

            if (!this->right_checked) 
            {
                if (this->array[right] > pivot) 
                {
                    this->array[right].SetFocus();
                    --this->right;
                    return;
                }
                else 
                {
                    this->right_checked = true;
                }
            }

            if (this->left < this->right) 
            {
                this->left_checked = false;
                this->right_checked = false;
                this->valid_ptrs = false;

                Element temp = this->array[this->left];
                this->array[this->left] = this->array[this->right];
                this->array[this->right] = temp;

                this->array[this->left].SetFocus();
                this->array[this->right].SetFocus();
                return;
            }
        }

        this->array[low] = this->array[right];
        this->array[right] = pivot;
        pivot_index = right;

        this->array[right].SetFocus();
        this->array[low].SetFocus();

        this->done_partitioning = true;
    }

    void QuickSort::Step() 
    {
        while (this->done_partitioning && !ranges.empty()) 
        {
            std::pair<int, int> r = ranges.top();
            ranges.pop();

            this->low = r.first;
            this->high = r.second;

            if (this->low == this->high)
                this->array[this->low].SetSorted();

            if (this->low < this->high) 
            {
                this->done_partitioning = false;
                this->pivot_set = false;
                break;
            }
        }

        if (this->done_partitioning && ranges.empty()) 
        {
            finished = true;
            return;
        }

        this->Partition();

        if (this->done_partitioning) 
        {
            this->array[pivot_index].SetSorted();

            if ((pivot_index - 1) - low + 1 <= high - (pivot_index + 1) + 1) 
            {
                ranges.push({ low, pivot_index - 1 });
                ranges.push({ pivot_index + 1, high});
            }
            else 
            {
                ranges.push({ pivot_index + 1, high});
                ranges.push({ low, pivot_index - 1 });
            }
        }
    }
}