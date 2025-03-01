# SortingVisualizer

Just a small C++ application, that uses Raylib v5.5 and Raygui v4.0 to visualize various sorting algorithms.

You can view the example gif below to see how it works! As you can see the application allows you to change the size of the array.

And it allows you to visualize many different algorithms, and most importantly, it allows you to HEAR THE SORTING!

![Example](https://github.com/v-jaroslav/SortingVisualizer/blob/main/example.gif)

## Running the application

You can do so by downloading one of the latest releases, from this github repo, or you can build the project yourself.

In order to build the project, you need to have cmake tool installed, and a C++ compiler.

To build the project, first you must clone it with `git clone https://github.com/v-jaroslav/SortingVisualizer`

After that position yourself to the directory SortingVisualizer with `cd SortingVisualizer`

Then you should run `cmake -B build` or `mkdir build && cd build && cmake ..`

If you want to, you could even provide a generator for build system of your choice, for example `Unix Makefiles` as `cmake -G "Unix Makefiles" -B build` or `mkdir build && cd build && cmake -G "Unix Makefiles" ..`

After that, make sure you are again positioned at the root of the project directory, so if you ran the latter command with `mkdir` etc, then run `cd ..`

After that, you can build the project with `cmake --build build`, and then in the build directory you should be able to find `SortingVisualizer.exe` that has been compiled, run it.
The exact location of executable highly depends on the generator you have used with cmake, so you have to find it yourself.

If you don't want to do all of that, then you can just simply download one of the releases as it has been said before.
Regardless, as long as you have a cmake and C++ compiler, you should be able to build this, as all dependencies are within the repository.
