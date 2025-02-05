#include "core_system/element.hpp"


namespace SortingVisualizer::CoreSystem
{
    Element::Element(int initial_value, Color regular_color, Color focus_color)
        : value(initial_value), focus(false), current_fill(regular_color), focus_fill(focus_color) { }

    void Element::SetValue(int value)
    {
        this->value = value;
    }
    
    void Element::SetFill(Color fill)
    {
        this->current_fill = fill;
    }

    void Element::SetFocus(bool focus)
    {
        this->focus = focus;
    }

    int Element::GetValue() const
    {
        return this->value; 
    }

    Color Element::GetFill()
    {
        if (this->focus)
            return this->focus_fill;
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