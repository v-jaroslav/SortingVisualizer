#include <raylib.h>

int main()
{
    InitWindow(800, 600, "Hello World");
    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
    }

    return 0;
}