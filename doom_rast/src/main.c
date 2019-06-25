#include "includes.h"

int main()
{
	t_wn wn;

	SDL_Init(SDL_INIT_VIDEO);
	wn.window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	return (0);	
}