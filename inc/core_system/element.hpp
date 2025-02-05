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
        Element(int initial_value = 0, Color initial_fill = WHITE);

        void SetValue(int value);
        void SetFill(Color fill);
        
        void Focus(Color focus);

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