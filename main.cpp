#include "SDL.h"
#undef main
#include <iostream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


SDL_Renderer* renderer;
SDL_Window* window;
bool isRunning;

void Init();
void Update();
void Render();


int main() {

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!\n";

        window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);


        if (window) {
            std::cout << "Window Created!\n";
            SDL_SetWindowMinimumSize(window, 100, 100);
        }
        else if (!window) {
            printf("Error: Failed to open window\nSDL Error: '%s'\n", SDL_GetError());
            return 1;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) {
            printf("Error: Failed to create renderer\nSDL Error: '%s'\n", SDL_GetError());
            return 1;
        }
        else if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
            std::cout << "Renderer created!\n";
            SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
            isRunning = true;
        }

    }


    while (isRunning) {
        SDL_Event event;
        SDL_PollEvent(&event);


        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE)
                {
                    printf("hello!");
                }
            default:
                break;
        }
        
        SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        Update();
        Render();
        
    }

    //frees memory associated with renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);	//error here
    SDL_Quit();


    return 0;
}



void Update() {

}

void render() {
    
}
