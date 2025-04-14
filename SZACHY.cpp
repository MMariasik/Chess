// by MM

#include "Tszachownica.h"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

constexpr int windowWidth{ 812 }, windowHeight{ 512 };

void UpdateDrawFrame(Tszachownica * szachy);

int main()
{

    InitWindow(windowWidth, windowHeight, "Szachy   byMM"); 
    InitAudioDevice();


#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    Tszachownica plansza;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame(&plansza);
    }
#endif

    CloseAudioDevice();
    CloseWindow();
}

void UpdateDrawFrame(Tszachownica * szachy)
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    szachy->dzialaj();


    EndDrawing();
}

