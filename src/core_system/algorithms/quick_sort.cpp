#include "core_system/algorithms/quick_sort.hpp"

namespace SortingVisualizer::CoreSystem::Algorithms
{
    void QuickSort::Prepare() 
    {
        this->ranges = std::stack<std::pair<int, int>>();
        this->ranges.push({ 0, this->array.GetNumberOfVisibleElements() - 1 });

        this->done_partitioning = true;
        this->initialized_partitioning = false;
    }

    void QuickSort::Partition() 
    {
        /* 
            This code is trying to simulate:

            left = low
            right = high
            pivot = arr[low]

            while (left < right)
            {
                while (arr[left] <= pivot && left < right)
                    ++left;
                    
                while (arr[right] > pivot)
                    --right;
                    
                if (left < right)
                    swap(arr[left], arr[right])
            }
            
            arr[low] = arr[right]
            arr[right] = pivot
            return right
        */

        if (!this->initialized_partitioning) 
        {
            // If we haven't initialized the partitioning, now it's time to do so, the pivot is at array[low], let left_ptr = low and right_ptr = high.
            this->pivot = this->array[this->low];
            this->pivot_index = this->low;
            this->left_ptr = this->low;
            this->right_ptr = this->high;

            // Set the flag to false that we haven't finished with the outter loop that we are simulating, nor the two inner ones.
            this->valid_ptrs = false;
            this->move_left_ptr_done = false;
            this->move_right_ptr_done = false;

            // Remember that we did initialize partitioning.
            this->initialized_partitioning = true;
        }

        // In case left_ptr < right_ptr then remember that they are valid. Basically set the condition for "outter loop".
        if (this->left_ptr < this->right_ptr) 
            this->valid_ptrs = true;

        if (this->valid_ptrs) 
        {
            if (!this->move_left_ptr_done) 
            {
                // If we haven't finished moving the left pointer, then move it in case that element it points to is smaller or equal than pivot, which means its in valid left partition.
                // And return after doing that, as we can't continue doing anything else until we are done with this first inner "loop".
                if (this->array[left_ptr] <= pivot && left_ptr < right_ptr) 
                {
                    this->array[left_ptr].SetFocus();
                    ++this->left_ptr;
                }
                else 
                {
                    this->move_left_ptr_done = true;
                }
                return;
            }

            if (!this->move_right_ptr_done)  
            {
                // If we haven't finished moving the right pointer, then move it in case that element it points to is greater than pivot, which means its in valid right partition.
                // If it isn't we finished with this "inner loop" so remember that by setting flag to true.
                if (this->array[right_ptr] > pivot) 
                {
                    this->array[right_ptr].SetFocus();
                    --this->right_ptr;
                }
                else 
                {
                    this->move_right_ptr_done = true;
                }
                return;
            }

            if (this->left_ptr < this->right_ptr) 
            {
                // If the pointers are still valid and didn't cross each other, then the reason the two "inner loops" ended is because they point to elements that arent supposed to be in their partitions.
                // Swap the elements that left and right pointers point to that are in invalid partitions.
                std::swap(this->array[this->left_ptr], this->array[this->right_ptr]);
                this->array[this->left_ptr].SetFocus();
                this->array[this->right_ptr].SetFocus();

                // Reset the flags so that we can repeat the "loops" again.
                this->move_left_ptr_done = false;
                this->move_right_ptr_done = false;
                this->valid_ptrs = false;
                return;
            }
        }

        // Once we are out of "loop" right < left is true, and right points to the last element of left partition that is smaller or equal to the pivot.
        // So let's swap the pivot at the index low and right_ptr. After that, everything to the left of pivot is smaller or equal to it, and everything to the right of it is greater than it.
        this->array[low] = this->array[right_ptr];
        this->array[right_ptr] = pivot;
        pivot_index = right_ptr;

        this->array[right_ptr].SetFocus();
        this->array[low].SetFocus();

        // Remember that we are done with partitioning.
        this->done_partitioning = true;
    }

    void QuickSort::Step() 
    {
        while (this->done_partitioning && !ranges.empty()) 
        {
            // If we finished partitioning last range, and we still have ranges left to partition, pick the top range from the stack to partition next.
            auto[l, h] = ranges.top();
            ranges.pop();

            // In case the size of the range is 1, then it has 1 element, and this range is sorted for sure (as it has 1 element), so set that element to be of that state.
            if (l == h)
                this->array[l].SetSorted();

            if (l < h) 
            {
                // If the range is valid set the low to be l and high to be h, so that we know which range to partition.
                // And set flag that we did not finish partition this range, and that we haven't started partitioning yet, exit loop.
                this->low = l;
                this->high = h;
                this->done_partitioning = false;
                this->initialized_partitioning = false;
                break;
            }
        }

        // If we finished partitioning, and we are out of [low, high] ranges to partition, then the quick sort is complete.
        if (this->done_partitioning && ranges.empty()) 
        {
            finished = true;
            return;
        }

        // Step the partition of the picked range.
        this->Partition();

        if (this->done_partitioning) 
        {
            // If we are done partitioning, then set the pivot to be in "sorted state", as everything to the left of pivot is smaller or equal to it, and everything to the right is greater than it.
            this->array[pivot_index].SetSorted();

            if ((pivot_index - 1) - low + 1 <= high - (pivot_index + 1) + 1) 
            {
                // If [low, pivot_index - 1] has smaller size than [pivot_index + 1, high], then add that range last, as thats the next range we want to process to use the stack less.
                ranges.push({ pivot_index + 1, high});
                ranges.push({ low, pivot_index - 1 });
            }
            else 
            {
                // If [pivot_index + 1, high] has smaller size than [low, pivot_index - 1], then add that range last, as thats the next range we want to process to use the stack less.
                ranges.push({ low, pivot_index - 1 });
                ranges.push({ pivot_index + 1, high});
            }
        }
    }
}