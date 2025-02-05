#ifndef SORTING_VISUALIZER_APPLICATION_HPP
#define SORTING_VISUALIZER_APPLICATION_HPP

#include "control_panel.hpp"
#include "core_system/array.hpp"

namespace SortingVisualizer
{
    class Application
    {
    private:
        UserInterface::ControlPanel controls;
        CoreSystem::Array array;

    public:
        Application();
        void run();
    };
}

#endif