#include <iostream>
#include "nikees_headers/Size.h"
#include "nikees_headers/Vector2.h"
#include "Game.hpp"


constexpr auto SCREEN_WIDTH = 800;
constexpr auto SCREEN_HEIGHT = 600;


SDL_Rect box;
double speed = 5;
Vector2* box_vel = new Vector2(0, 0);
bool MoveUp = false;
bool MoveDown = false;
bool MoveLeft = false;
bool MoveRight = false;

Uint8 background_color[4] = { 100, 149, 237, 255 };



Game::Game()
{
	window = SDL_CreateWindow("game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0);

	if (!window)
	{
		std::cout << "Failed to create window\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!renderer)
	{
		std::cout << "Failed to get window's surface\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return;
	}

}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Game::loop()
{
	

	box.x = SCREEN_WIDTH / 2 - 10;
	box.y = SCREEN_HEIGHT / 2 - 10;
	box.w = 20;
	box.h = 20;

	isRunning = true;

	while (isRunning)
	{
		while (SDL_PollEvent(&event) > 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					box_vel->x = -speed;
					break;
				case SDLK_RIGHT:
					box_vel->x = speed;
					break;
				case SDLK_UP:
					box_vel->y = -speed;
					break;
				case SDLK_DOWN:
					box_vel->y = speed;
					break;
				case SDLK_ESCAPE:
					isRunning = false;
					break; 
				default:
					break;
				}
				break;
								
			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					if (box_vel->x < 0)
						box_vel->x = 0;
					break;

				case SDLK_RIGHT:
					if (box_vel->x > 0)
						box_vel->x = 0;
					break;

				case SDLK_UP:
					if (box_vel->y < 0)
						box_vel->y = 0;
					break;

				case SDLK_DOWN:
					if (box_vel->y > 0)
						box_vel->y = 0;
					break;
				default:
					break;
				}
			default:
				break;
			}
		}

		update(1.0 / 60.0);
		draw();
	}
}


void Game::update(double delta_time)
{

	box.x += box_vel->x;
	box.y += box_vel->y;

}

void Game::draw()
{
	SDL_RenderClear(renderer);


	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &box);
	
	SDL_SetRenderDrawColor(renderer, background_color[0], background_color[1], background_color[2], background_color[3]);

	SDL_RenderPresent(renderer);
}
