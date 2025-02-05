#ifndef SORTING_VISUALIZER_CORE_SYSTEM_ELEMENT_HPP
#define SORTING_VISUALIZER_CORE_SYSTEM_ELEMENT_HPP

#include <raylib.h>

namespace SortingVisualizer::CoreSystem
{
    class Element
    {
    private:
        int value;
        Color fill;

    public:
        Element(int initial_value = 0, Color initial_fill = WHITE);

        void SetValue(int value);
        void SetFill(Color fill);

        int GetValue() const;
        Color GetFill() const;
        
        bool operator <  (const Element& other) const;
        bool operator <= (const Element& other) const;

        bool operator >  (const Element& other) const;
        bool operator >= (const Element& other) const;

        bool operator == (const Element& other) const;
        bool operator != (const Element& other) const;
    };
}

#endif