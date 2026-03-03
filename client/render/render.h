#ifndef RENDER_H
#define RENDER_H

#include <SDL3/SDL_render.h>
#include "../client.h"

typedef struct {
	float x;
	float y;
} Position;

typedef struct {
	float direction; // in radians
	Position pos;
	int speed;
} Object;

typedef struct {
	Object obj;
	int radius;
} Circle;


typedef struct {
	float originx;
	float originy;
	float tailx;
	float taily;
} line;


void render_circle(SDL_Renderer* renderer, Circle* circle);
void render_line(SDL_Renderer* renderer, line* line);
void render_text(App* app, text_component* text_rect);
void init_font(App* app);

#endif


