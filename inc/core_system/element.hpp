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

        Color current_fill;
        Color focus_fill;
        
    public:
        Element(int initial_value = 0, Color regular_color = WHITE, Color focus_color = RED);

        void SetValue(int value);
        void SetFill(Color fill);
        
        void SetFocus(bool focus = true);

        int GetValue() const;
        Color GetFill();
        
        bool operator <  (const Element& other) const;
        bool operator <= (const Element& other) const;

        bool operator >  (const Element& other) const;
        bool operator >= (const Element& other) const;

        bool operator == (const Element& other) const;
        bool operator != (const Element& other) const;
    };
}

#endif