#include "core_system/algorithms/algorithm.hpp"


namespace SortingVisualizer::CoreSystem::Algorithms
{
    Algorithm::Algorithm(Array& a)
        : array(a) { }
    
    bool Algorithm::IsDone() const
    {
        return this->finished;
    }
    
    void Algorithm::Reset()
    {
        // The algorithm is now not finished! As it's reset to be run.
        this->finished = false;

        for (int i = 0; i < this->array.GetNumberOfVisibleElements(); ++i)
        {
            // Before we start, reset states of each element, to not be focused with red color and to not be sorted (shown with blue color).
            this->array[i].SetFocus(false);
            this->array[i].SetSorted(false);
        }
        
        // And call the prepare method that every subclass should implement. Every algorithm requires different preparations.
        this->Prepare();
    }
}