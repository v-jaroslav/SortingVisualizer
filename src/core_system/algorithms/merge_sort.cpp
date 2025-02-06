#include "core_system/algorithms/merge_sort.hpp"

#include <algorithm>

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void MergeSort::Prepare() 
    {
        // For the iterative merge sort, we start with partitions of size 1, and our partition starts at low=0.
        this->partition_size = 1;
        this->low = 0;

        // And also, initially we haven't merged any partitions, and havent copied them to temporary arrays.
        this->merge_done = this->coppied = false;
    }

    void MergeSort::Merge(int low, int mid, int high) 
    {
        if (!this->coppied) 
        {
            // The size of range [low, mid] is mid - low + 1, and the size of the range [mid + 1, high] is high - (mid + 1) - 1.
            this->left_len = mid - low + 1;
            this->right_len = high - mid;

            // Copy the partitions to buffers.
            for (int i = 0; i < this->left_len; ++i)
                this->left_tmp[i] = this->array[low + i].GetValue();

            for (int i = 0; i < this->right_len; ++i)
                this->right_tmp[i] = this->array[mid + 1 + i].GetValue();

            // Remember that you have copied the partitions to buffers so that we dont do this again.
            this->coppied = true;
            
            // Reset the l and r pointers in the temporary buffers to point to next element we can take from them.
            // And let the free pointer point to the first slot at which we can store the value from temporary buffers.
            this->l = this->r = 0;
            this->free = low;
        }

        if (l < left_len && r < right_len) 
        {
            // As long as we didn't use up elements from either of the buffers, pick the smaller element from either of the buffers.
            // Store the element at array[free], and move free pointer and the pointer for the specific buffer.
            if (left_tmp[l] < right_tmp[r]) 
            {
                this->array[free].SetValue(left_tmp[l++]);
                this->array[free++].SetFocus();
            }
            else 
            {
                this->array[free].SetValue(right_tmp[r++]);
                this->array[free++].SetFocus();
            }
        }
        else 
        {
            // If we have used up elements of one buffer, maybe other one isn't empty, so just copy elements from it to array.
            // If we used up all the elements, then merging is complete.
            if (l < left_len) 
            {
                this->array[free].SetValue(left_tmp[l++]);
                this->array[free++].SetFocus();
            }
            else if (r < right_len) 
            {
                this->array[free].SetValue(right_tmp[r++]);
                this->array[free++].SetFocus();
            }
            else 
            {
                this->merge_done = true;
            }
        }
    }

    void MergeSort::Step() 
    {
        // We will be performing merge sort, only if the partition size is smaller than the size of the array.
        if (partition_size < this->array.GetNumberOfVisibleElements()) 
        {
            // We can merge [low, mid=(low + partition_size - 1)] and [low + partition_size, high=(low + partition_size + (partition_size - 1))].
            // Only if low has its right neighbor, if it doesn't then for sure there is no other partition to the right of us.
            if (low + 1 < this->array.GetNumberOfVisibleElements()) 
            {
                // We limit the upper bound to the (n - 1) as that is the last valid index.
                int mid = std::min(low + partition_size - 1, this->array.GetNumberOfVisibleElements() - 1);
                int high = std::min(low + 2 * partition_size - 1, this->array.GetNumberOfVisibleElements() - 1);
                this->Merge(low, mid, high);

                if (this->merge_done) 
                {
                    // If the merge happened, then we want to move to the next pair of two partitions to merge, so set low = high + 1. And reset merge/copy flags.
                    low = low + 2 * partition_size;
                    this->merge_done = false;
                    this->coppied = false;
                }
            }
            else 
            {
                // If the low does not have a right neighbor, then it doesn't have a neighboring partition to merge it with.
                // So we merged all the partitions of the partition_size, we have x2 less partitions but they are x2 bigger.
                this->partition_size = 2 * this->partition_size;
                this->low = 0;
            }
        }
        else
        {
            // If the partition size is not smaller than array size, so if it is equal to the size of array. 
            // That means we would have to merge it with another partition of the same size, so we would need two arrays of these sizes, which we don't have.
            this->finished = true;
        }
    }
}