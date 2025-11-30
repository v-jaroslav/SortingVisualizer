# SortingVisualizer

A small C++ application, that uses Raylib v5.5 and Raygui v4.0 to visualize various sorting algorithms.

You can view a GIF below (wait for it to load) to see how it works! As you can see the application allows you to change the size of the array.

And it allows you to visualize many different algorithms, and most importantly, it allows you to **hear the sorting**!

![GIF](https://github.com/v-jaroslav/SortingVisualizer/blob/main/example.gif)

## Running the application

You can do so by downloading one of the latest releases, from this github repository, or you can build the project yourself.

In order to build the project, you need to have cmake tool installed, and a C++ compiler.

To build the project, first you must clone it with `git clone https://github.com/v-jaroslav/SortingVisualizer`.

After that position yourself to the root directory of the project with `cd SortingVisualizer`.

Then you should run `cmake -B build` or `mkdir build && cd build && cmake ..`.

If you want to, you can even provide a generator for build system of your choice, for example `Unix Makefiles` with `cmake -G "Unix Makefiles" -B build` or `mkdir build && cd build && cmake -G "Unix Makefiles" ..`

After that, position yourself inside the root directory of the project again, and then you can build the project with `cmake --build build --config Release`. 
Then in the build directory you should be able to find the built executable, run it.
