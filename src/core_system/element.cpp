#include "core_system/element.hpp"


namespace SortingVisualizer::CoreSystem
{
    Element::Element(int initial_value, Color initial_fill)
        : value(initial_value), fill(initial_fill) { }

    void Element::SetValue(int value)
    {
        this->value = value;
    }

    void Element::SetFill(Color fill)
    {
        this->fill = fill;
    }

    int Element::GetValue() const
    {
        return this->value; 
    }

    Color Element::GetFill() const
    {
        return this->fill;
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