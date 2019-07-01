#include <SDL2/SDL.h>

typedef struct s_wn
{
	SDL_Window 	*window;
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Renderer *renderer;
	SDL_Rect dest;
	SDL_Event event;
}				t_wn;