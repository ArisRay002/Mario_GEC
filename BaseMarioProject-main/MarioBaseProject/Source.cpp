#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Constants.h"
#include <iostream>
#include "Texture2D.h"
#include "Commons.h"

using namespace std;

SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
Texture2D* g_texture = nullptr;

bool InitSDL();
void CloseSDL();
bool Update();
void Render();
bool InitSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL did not initialise. Error: " << SDL_GetError();
        return false;
    }

    else
    {
        g_window = SDL_CreateWindow("Games Engine Creation",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);

        if (g_window == nullptr)
        {
            //window failed
            cout << "Window was not created. Error: " << SDL_GetError();
            return false;
        }

        g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

        if (g_renderer != nullptr)
        {
            int imageFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imageFlags) & imageFlags))
            {
                cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
                return false;
            }
        }

        else
        {
            cout << "Renderer could not initialise. Error: " << SDL_GetError();
            return false;
        }

        g_texture = new Texture2D(g_renderer);

        if (!g_texture->LoadFromFile("Images/test.bmp"))
        {
            return false;
        }

    }

    return true;
}
void CloseSDL()
{
    SDL_DestroyWindow(g_window);
    g_window = nullptr;
    SDL_DestroyRenderer(g_renderer);
    g_renderer = nullptr;
    IMG_Quit();
    SDL_Quit();
    delete g_texture;
    g_texture = nullptr;

}
bool Update()
{
    SDL_Event e;
    SDL_PollEvent(&e);
    switch (e.type)
    {
        case SDL_QUIT:
            return true;
            break;
    }
    return false;
}
void Render()
{
    SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(g_renderer);
    g_texture->Render(Vector2D(), SDL_FLIP_NONE);
    SDL_RenderPresent(g_renderer);
}

int main(int argc, char* args[])
{   
    if (InitSDL())
    {
        bool quit = false;
        while (!quit)
        {
            Render();
            quit = Update();
        }
    }
    CloseSDL();
    return 0;
}