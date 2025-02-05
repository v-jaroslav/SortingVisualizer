#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ARRAY_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ARRAY_HPP

#include "constants.hpp"
#include "core_system/element.hpp"

namespace SortingVisualizer::CoreSystem
{
    class Array
    {
    private:
        Element buffer[Constants::Application::MAX_NUM_OF_ELEMS];
        int n_visible_elems;

        void InitializeBuffer();

    public:
        Array();
        
        void SetNumberOfVisibleElements(int n_visible_elems);
        int GetNumberOfVisibleElements() const;
        
        Element& operator[] (int i);
        const Element& operator[] (int i) const;

        void Draw();
    };
}

#endif