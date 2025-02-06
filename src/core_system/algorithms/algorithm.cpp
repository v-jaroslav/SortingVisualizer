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
        this->finished = false;
        for (int i = 0; i < this->array.GetNumberOfVisibleElements(); ++i)
        {
            this->array[i].SetFocus(false);
            this->array[i].SetSorted(false);
        }
        this->Prepare();
    }
}