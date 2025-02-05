#include "core_system/element.hpp"


namespace SortingVisualizer::CoreSystem
{
    Element::Element(int initial_value, Color initial_fill)
        : value(initial_value), current_fill(initial_fill) { }

    void Element::SetValue(int value)
    {
        this->value = value;
    }
    
    void Element::SetFill(Color fill)
    {
        this->current_fill = fill;
    }

    void Element::Focus(Color focus)
    {
        this->focus_fill = focus;
        this->focus = true;
    }


    int Element::GetValue() const
    {
        return this->value; 
    }

    Color Element::GetFill()
    {
        if (this->focus)
        {
            this->focus = false;
            return this->focus_fill;
        }

        return this->current_fill;
    }
    
    bool Element::operator < (const Element& other) const
    {
        return this->value < other.value; 
    }

    bool Element::operator <= (const Element& other) const
    {
        return this->value <= other.value; 
    }

    bool Element::operator > (const Element& other) const
    {
        return this->value > other.value; 
    }

    bool Element::operator >= (const Element& other) const
    {
        return this->value >= other.value; 
    }

    bool Element::operator == (const Element& other) const
    {
        return this->value == other.value; 
    }

    bool Element::operator != (const Element& other) const
    {
        return this->value != other.value; 
    }
}