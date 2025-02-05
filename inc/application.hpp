#ifndef SORTING_VISUALIZER_APPLICATION_HPP
#define SORTING_VISUALIZER_APPLICATION_HPP

#include <memory>

#include "control_panel.hpp"
#include "core_system/array.hpp"
#include "core_system/algorithms/algorithm.hpp"
#include "core_system/algorithms/fisher_yates_shuffle.hpp"

namespace SortingVisualizer
{
    class Application
    {
    private:
        UserInterface::ControlPanel controls;
        CoreSystem::Array array;
        
        bool run_shuffler = false;
        CoreSystem::Algorithms::FisherYatesShuffle shuffler;          
        
        bool run_sort = false;
        std::shared_ptr<CoreSystem::Algorithms::Algorithm> sorting_strategy;

        void RenderGraphics();
        void HandleUserInput();
        void UpdateLogic();

    public:
        Application();
        void run();
    };
}

#endif