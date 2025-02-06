#ifndef SORTING_VISUALIZER_APPLICATION_HPP
#define SORTING_VISUALIZER_APPLICATION_HPP

#include <memory>

#include "control_panel.hpp"
#include "core_system/array.hpp"
#include "core_system/algorithms/algorithm.hpp"
#include "core_system/algorithms/fisher_yates_shuffle.hpp"
#include "core_system/algorithms/algorithm_factory.hpp"

namespace SortingVisualizer
{
    class Application
    {
    private:
        UserInterface::ControlPanel controls;
        CoreSystem::Array array;
        
        bool run_shuffler;
        CoreSystem::Algorithms::FisherYatesShuffle shuffler;
        
        bool run_sort;
        std::shared_ptr<CoreSystem::Algorithms::Algorithm> sorting_strategy;
        using AlgorithmFactory = CoreSystem::Algorithms::AlgorithmFactory;
        
        bool play_sound;

        void RenderGraphics();
        void HandleUserInput();
        void UpdateLogic();

    public:
        Application();
        void run();
    };
}

#endif