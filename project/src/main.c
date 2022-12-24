#include "../include/battle.h"
#include "../include/common.h"
#include "../include/definitions.h"
#include "../include/init.h"
#include "../include/pokemon.h"
#include "../include/queue.h"
#include "../include/sdldef.h"

int main(int argc, char **argv)
{
	randseed = time(NULL);
	srand(randseed);
	system("/bin/stty echo");
	system("/bin/stty cooked");
	printf("\e[?25h");
	init_free_queue(&garbage_strings);
	InitSDL();
	bool running = true;

	while (1) {
		Battle();
	}

	while (running) {
		// lastframestart = framestart;
		framestart = SDL_GetTicks();

		// Process events
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_RIGHT) {
				}
				else if (event.key.keysym.sym == SDLK_LEFT) {
				}
				else if (event.key.keysym.sym == SDLK_UP) {
				}
				else if (event.key.keysym.sym == SDLK_DOWN) {
				}
			}
			else {
			}
		}

		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Draw
		lastdraw = thisdraw;
		thisdraw = SDL_GetTicks();
		timesincelastdraw = thisdraw - lastdraw;

		// Show what was drawn
		SDL_RenderPresent(renderer);

		frametime = SDL_GetTicks() - framestart;
		if (framedelay > frametime) {
			SDL_Delay(framedelay - frametime);
		}
	}

	// Release resources
	IMG_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	// system("clear");
	return 0;
}
