#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <stdio.h>
#include "../client.h"

#define TITLE_H 10
#define TITLE_TEXT "enter your username"


static void init(App* app) {
		
	// app->frame_data.enter_username.input_component = 

}


static void input(App* app, SDL_Event* event) {
	if (event->type == SDL_EVENT_KEY_DOWN) {
		SDL_Keycode key = event->key.key;

		switch (key) {
			case SDLK_BACKSPACE:
				printf("backspace\n");
				break;
			case SDLK_RETURN:
				printf("return\n");
				break;
		}
	}
	if (event->type == SDL_EVENT_TEXT_INPUT) {
		printf("text input\n");
	}
}



static void render(App* app) {
	printf("rendering enter_username\n");
	SDL_Renderer* renderer = app->renderer;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

// void render_circle(SDL_Renderer *renderer, Circle *circle) {
	render_circle(app->renderer, );
	// SDL_RenderLine(SDL_Renderer *renderer, float x1, float y1, float x2, float y2)
}





extern fr_handler h_enter_username = (fr_handler){
	.init = (init_handler*)init,
	.input = (input_handler*)input,
	.render = (render_handler*)render,
};




