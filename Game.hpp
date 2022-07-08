#pragma once

#include <SDL.h>
#include <iostream>
#include <memory>
#include "nikees_headers/Size.h"
#include "nikees_headers/Vector2.h"

class Game
{
public:
    Game();
    ~Game();

    void loop();
    void update(double delta_time);
    void draw();

    bool isRunning;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event     event;

};
