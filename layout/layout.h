#ifndef LAYOUT_H
#define LAYOUT_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_pixels.h>


typedef void (render_func)(SDL_Renderer*, void*);

// SDL_Color

typedef struct {
	void* elt;
	SDL_Color color;
	render_func* render;
} renderable;


typedef struct {
	int id;
	renderable element;
	int num_children;
	struct Node** children;
} Node;

void render_root(SDL_Renderer* renderer, Node* root);

extern SDL_Color SDL_COLOR_YELLOW  = (SDL_Color){
	.r = 255,
	.g = 255,
	.b = 0,
	.a = 1,
};


extern SDL_Color  SDL_COLOR_BLUE  = (SDL_Color){
	.r = 0,
	.g = 0,
	.b = 255,
	.a = 1,
};

#endif
