#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <stdlib.h>
#include "../client.h"
#include "SDL3/SDL_render.h"
#include <render.h>


#define TITLE_H 10
#define TITLE_TEXT "enter your username"
#define TEXTBOX_HEIGHT 10
#define TEXTBOX_WIDTH 100
#define TEXTBOX_MARGIN 10
#define FR_MARGIN_LEFT 100
#define FR_MARGIN_TOP 100


// title rect ("enter username")
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
	SDL_StartTextInput(app->window);

	fr_enter_username* fr = &(app->frame_data.enter_username);
	init_title(fr);
	init_text_input(fr);
}


static void handle_backspace(fr_enter_username* frame) {
	int len = strlen(frame->input_component.text);
	if (len > 0) {
		frame->input_component.text[len - 1] = '\0';
	}
}

static void handle_return(App* app) {
	// stop taking input
	SDL_StopTextInput(app->window);

	// copy text_input to username
	strncpy(app->username, app->frame_data.enter_username.input_component.text, 25);

	// set game phase to pointing
	app->current_frame = select_opponent;
	
	// tcp_write_msg_1("username", app->username);
	//
	// tcp_write_msg_1("query", "players");
}

static void handle_text_input(fr_enter_username* frame, SDL_Event* event) {
	int len = strlen(frame->input_component.text);
	if (len < MAX_USERNAME_CHARS) {
		strcat(frame->input_component.text, event->text.text);
	}
}






static void input(App* app, SDL_Event* event) {
	fr_enter_username* fr = &(app->frame_data.enter_username);
	if (event->type == SDL_EVENT_KEY_DOWN) {
		SDL_Keycode key = event->key.key;

		switch (key) {
			case SDLK_BACKSPACE:
				handle_backspace(fr);
				break;
			case SDLK_RETURN:
				handle_return(app);
				break;
		}
	}
	if (event->type == SDL_EVENT_TEXT_INPUT) {
		handle_text_input(fr, event);
	}
}



static void render(App* app) {
	fr_enter_username* fr = &(app->frame_data.enter_username);
	SDL_Renderer* renderer = app->renderer;

	// clear the screen w/ black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

	// draw line and text with white
	render_text(app, &(fr->title_component));
	render_text(app, &(fr->input_component));
}





extern fr_handler h_enter_username = (fr_handler){
	.init = (init_handler*)init,
	.input = (input_handler*)input,
	.render = (render_handler*)render,
};




