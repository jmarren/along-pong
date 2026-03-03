#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <stdio.h>
#include <stdlib.h>
#include "../client.h"
#include "SDL3/SDL_render.h"

#define TITLE_H 10
#define TITLE_TEXT "enter your username"
#define TEXTBOX_HEIGHT 10
#define TEXTBOX_WIDTH 100
#define TEXTBOX_MARGIN 10
#define FR_MARGIN_LEFT 100
#define FR_MARGIN_TOP 100


static SDL_FRect title_rect = (SDL_FRect){
		.x = FR_MARGIN_LEFT,
		.y = FR_MARGIN_TOP,
		.w = TEXTBOX_WIDTH,
		.h = TEXTBOX_HEIGHT,
};



// text_input rect
static SDL_FRect text_input_rect = (SDL_FRect){
		.x = FR_MARGIN_LEFT,
		.y = FR_MARGIN_TOP + TITLE_H + 10,
		.w = TEXTBOX_WIDTH,
		.h = TEXTBOX_HEIGHT,
};

// initialize text input component
static void init_text_input(fr_enter_username* frame) {
	char* input_text = calloc(10, sizeof(char));
	frame->input_component = (text_component){
		.rect = text_input_rect,
		.text = input_text,
	};
}

// initialize text input
static void init_title(fr_enter_username* frame) {
	frame->title_component = (text_component){
		.rect = title_rect,
		.text = TITLE_TEXT,
	};
}



static void init(App* app) {
	// init_title(&(app->frame_data.enter_username));
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
	SDL_Renderer* renderer = app->renderer;
	// clear the screen w/ black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
	// draw line and text with white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderLine(renderer, 100.0, 200.0, 150.0, 250.0);
    	SDL_RenderDebugText(renderer, 100, 100, "hi there");
}





extern fr_handler h_enter_username = (fr_handler){
	.init = (init_handler*)init,
	.input = (input_handler*)input,
	.render = (render_handler*)render,
};




