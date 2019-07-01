#include "includes.h"

void input(t_wn *wn)
{
	SDL_PollEvent(wn->event);
}

int main()
{
	t_wn wn;

	SDL_Init(SDL_INIT_VIDEO);
	wn.window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	wn.renderer = SDL_CreateRenderer (wn.window, -1, SDL_RENDERER_ACCELERATED);
	wn.surface = SDL_LoadBMP("src/MARBLES.bmp");
	//wn.surface = IMG_Load("merc.bmp");
	if (wn.surface)
		printf("Surface loaded\n");
	else 
		printf("Surface not loaded: %s\n", SDL_GetError());
	wn.texture = SDL_CreateTextureFromSurface(wn.renderer, wn.surface);
	free(wn.surface);
	wn.surface = NULL;
	wn.dest.x = 400;
	wn.dest.y = 300;
	wn.dest.w = 100;
	wn.dest.h = 100;
	SDL_RenderCopy(wn.renderer, wn.texture, NULL, &wn.dest);
	SDL_RenderPresent(wn.renderer);
	while (TRUE)
	{
		input(&wn);
	}
	return (0);	
}