#ifndef SORTING_VISUALIZER_APPLICATION_HPP
#define SORTING_VISUALIZER_APPLICATION_HPP

#include "control_panel.hpp"
#include "core_system/array.hpp"
#include "core_system/algorithms/fisher_yates_shuffle.hpp"

namespace SortingVisualizer
{
    class Application
    {
    private:
        UserInterface::ControlPanel controls;
        CoreSystem::Array array;
        
        CoreSystem::Algorithms::FisherYatesShuffle shuffler;          
        bool run_shuffler = false;
        
        void RenderGraphics();
        void HandleUserInput();
        void UpdateLogic();

    public:
        Application();
        void run();
    };
}

#endif