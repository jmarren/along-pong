
#ifndef CLIENT_H
#define CLIENT_H

#include "uv.h"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <stdbool.h>
#include "../include/macro.h"



#define HOST "127.0.0.1"
#define PORT 7000
#define ACTIVE_USERS_CAP 50


typedef enum {
	initializing,
	enter_username,
	select_opponent,
	gameplay,
} frame;



typedef struct  {
	SDL_FRect rect;
	char* text;
} text_component;


typedef struct {
	text_component input_component;
	text_component title_component;
} fr_enter_username;


typedef struct { 
	fr_enter_username enter_username;
} frames_t;


typedef void (init_handler)(void* app);
typedef void (input_handler)(void* app, SDL_Event* event);
typedef void (render_handler)(void* app);
typedef struct {
	init_handler* init;
	input_handler* input;
	render_handler* render;
} fr_handler;

typedef struct {
	// always present
	uv_loop_t* loop;
	SDL_Renderer* renderer;
	SDL_Window* window;
	Uint32 read_event_type;
	frame current_frame;
	char username[MAX_USERNAME_CHARS];
	char opponent_username[MAX_USERNAME_CHARS];
	fr_handler handlers[5];
	frames_t frame_data;
} App;


void loop_start(App* app);



#endif



