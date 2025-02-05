#include "core_system/array.hpp"
#include "control_panel.hpp"

#include <iostream>

namespace SortingVisualizer::CoreSystem
{
    Array::Array()
        : n_visible_elems(Constants::Application::MIN_NUM_OF_ELEMS)
    {
        this->InitializeBuffer(); 
    }

    void Array::InitializeBuffer()
    {
        for (int i = 0; i < this->n_visible_elems; ++i)
        {
            this->buffer[i].SetFill(WHITE); 
            this->buffer[i].SetValue(i + 1);
        }
    }
    
    void Array::SetNumberOfVisibleElements(int n_visible_elems)
    {
        if (this->n_visible_elems == n_visible_elems)
            return;
        this->n_visible_elems = n_visible_elems;
        this->InitializeBuffer();
    }

    int Array::GetNumberOfVisibleElements() const
    {
        return this->n_visible_elems; 
    }
    
    Element& Array::operator[] (int i)
    {
        return this->buffer[i];
    }

    const Element& Array::operator[] (int i) const
    {
        return this->buffer[i];
    }

    void Array::Draw()
    {
        for (int i = 0; i < this->n_visible_elems; ++i)
        {
            // We want to display the whole array in the given window, so grab the width of the window, and divide it with the number of elements to display, to get the width of a single element.
            float element_width = ((float)UserInterface::GetScaledWidth()) / this->n_visible_elems;

            // Grab the value of the element, and divide it with the number of elements, to get a %, then multiply that with the height of the window, in order to get the height of the element.
            float element_height = ((float)this->buffer[i].GetValue()) / this->n_visible_elems * UserInterface::GetScaledHeight();

            // 0-th element should be occupy [0, element_width - 1] x coordinates, 1-st element should occupy [element_width, element_width + (element_width - 1)] and so on.
            // Therefore draw each element from i*element_width x axis. And also, y=0 is at the top of the window, we want that to be at the bottom, as we want to draw elements at the bottom.
            // Therefore, grab the height of the window, and subtract from it the height of the element, thats the y axis to draw the element from, if we draw the element of its height from that y coordinate, it will go to the bottom of the window.
            DrawRectangleV({ i * element_width, UserInterface::GetScaledHeight() - element_height }, { element_width, element_height }, this->buffer[i].GetFill());
        }
    }
}