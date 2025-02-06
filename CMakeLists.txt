# Define minimum version of cmake tool, and basic information related to the project (name, version, description, language).
cmake_minimum_required(VERSION 3.10)
project(SortingVisualizer VERSION 1.0 DESCRIPTION "Application that visualizes many sorting algorithms." LANGUAGES CXX)


# Define that we want to use C++20, and turn off compiler specific extensions (through cmake variables).
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Define raylib and raygui library locations.
set(RaylibDir ${CMAKE_SOURCE_DIR}/dependencies/raylib-5.5)
set(RayguiDir ${CMAKE_SOURCE_DIR}/dependencies/raygui-4.0)

# Evaluate CMakeLists.txt for raylib. Build it along with this project.
add_subdirectory(${RaylibDir})


# In src/ find all .cpp files recursively, and create executable that has the same name as project and depends on all of those .cpp files.
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Additional user include dir, for the project target (without other projects having ability to see it).
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)


# Additional third party library include dirs.
target_include_directories(${PROJECT_NAME} PRIVATE ${RaylibDir}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${RaylibDir}/src/external)
target_include_directories(${PROJECT_NAME} PRIVATE ${RayguiDir}/src)

# Additional libraries to link. MSVC compiler will look for <library_name>.lib, g++ may look for lib<library_name>.a, etc.
# We didn't have to specify link directory for raylib as we evaluate CMakeLists.txt of raylib source code, it gets automatically handled.
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PRIVATE opengl32)
target_link_libraries(${PROJECT_NAME} PRIVATE gdi32)
target_link_libraries(${PROJECT_NAME} PRIVATE winmm)
