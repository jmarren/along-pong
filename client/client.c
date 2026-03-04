#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "macro.h"
#include <SDL3/SDL_init.h>
#include <stdio.h>
#include "client.h"
#include <render.h>
#include <frames.h>

App app;


void init_sdl(void) {

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window** window = &(app.window);
	SDL_Renderer** renderer = &(app.renderer);

	int create_window = SDL_CreateWindowAndRenderer("Hello World", WINDOW_W, WINDOW_H, SDL_WINDOW_FULLSCREEN, window, renderer);
		
	if (!create_window) {
		printf("failed to create window\n");
		SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
	};


	SDL_ShowWindow(app.window);
	SDL_RaiseWindow(app.window);
}



int main(void) {

	init_sdl();

	init_font(&app);

	app.handlers[enter_username] = h_enter_username;

	app.current_frame = enter_username;

	loop_start(&app);

	return 0;
}
