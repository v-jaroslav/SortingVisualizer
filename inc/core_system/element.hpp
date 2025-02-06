#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ELEMENT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ELEMENT_HPP

#include <raylib.h>

namespace SortingVisualizer::CoreSystem
{
    class Element
    {
    private:
        int value;
        bool focus;
        bool sorted;

        Color regular_fill;
        Color sorted_fill;
        Color focus_fill;
        
    public:
        Element(int initial_value = 0, Color regular_color = WHITE, Color sorted_color = BLUE, Color focus_color = RED);

        int GetValue() const;
        void SetValue(int value);

        void SetFocus(bool focus = true);
        void SetSorted(bool sorted = true);

        Color GetFill();
        
        // All comparison operators are here for the sake of completeness.
        bool operator <  (const Element& other) const;
        bool operator <= (const Element& other) const;

        bool operator >  (const Element& other) const;
        bool operator >= (const Element& other) const;

        bool operator == (const Element& other) const;
        bool operator != (const Element& other) const;
    };
}

#endif