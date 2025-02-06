#include "core_system/element.hpp"
#include "core_system/tone_generator.hpp"
#include "constants.hpp"

namespace SortingVisualizer::CoreSystem
{
    Element::Element(int initial_value, Color regular_color, Color sorted_color, Color focus_color)
        : value(initial_value), focus(false), sorted(false), regular_fill(regular_color), sorted_fill(sorted_color), focus_fill(focus_color) { }

    int Element::GetValue() const
    {
        return this->value; 
    }

    void Element::SetValue(int value)
    {
        this->value = value;
    }
    
    void Element::SetFocus(bool focus)
    {
        this->focus = focus;
        if (focus)
            ArrayToneGenerator::SetFrequency(this->value);
    }

    void Element::SetSorted(bool secondary)
    {
        this->sorted = secondary;
        if (secondary)
            ArrayToneGenerator::SetFrequency(this->value);
    }

    Color Element::GetFill()
    {
        if (this->focus)
            return this->focus_fill;
        if (this->sorted)
            return this->sorted_fill;
        return this->regular_fill;
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