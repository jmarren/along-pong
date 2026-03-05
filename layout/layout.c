#include "layout.h"
#include <stdio.h>

void init(void) {
	
	// SDL_FRect root_rect = (SDL_FRect){
	// 	.h = 100,
	// 	.w = 100,
	// 	.x = 100,
	// 	.y = 100,
	// };
	//
	//
	// renderable root_elt = (renderable){
	// 	.elt = (void*)&root_rect,
	// 	.render = (render_func*)&SDL_RenderRect,
	// };
	//
	//

}


void render_root(SDL_Renderer* renderer, Node* root) {
	SDL_Color c = root->element.color;

	SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
	root->element.render(renderer, root->element.elt);
	
	printf("root->id = %d\n", root->id);

	for (int i = 0; i < root->num_children; i++) {
		render_root(renderer, (root->children[i]));
	}
	
}

