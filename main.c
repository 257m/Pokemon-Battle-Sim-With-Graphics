#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <malloc.h>
#include <limits.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "definitions/enumdefs.h"
#include "def.h"
#include "drawing/fonts.h"
#include "drawing/UIelements.h"
#include "SpriteInfo/offsets.h"

#include "predefs/queue.h"
#include "predefs/stringfuncs.h"
#include "predefs/gnrltxt.h"
#include "predefs/gnrlfuncs.h"
#include "definitions/definitions.h"
#include "effects/effectfuncs.h"
#include "effects/effects.h"
#include "moves/movedata.h"
#include "moves/movefuncs.h"
#include "abilities/abilities.h"
#include "abilities/abilityfuncs.h"
#include "pokemon/pokedata.h"
#include "items/helditems.h"
#include "items/itemfuncs.h"
#include "drawing/anim.h"
#include "display/displayparty.h"
#include "other/win.h"
#include "other/switching.h"
#include "display/displayfuncs.h"
#include "executions/execution.h"
#include "executions/endofturn.h"
#include "pokemon/partyset.h"
#include "other/statcalc.h"
#include "other/retrieve.h"
#include "battle.h"

/*#define Display_Img(image, x, y) ({\
image.rect.x = x;\
image.rect.y = y;\
SDL_RenderCopy(renderer, image.texture, NULL, &image.rect);\
})*/

int main(int argc, char **argv)
{
    randseed = time(NULL);
    srand(randseed);
    system("/bin/stty echo");
    system ("/bin/stty cooked");
    printf("\e[?25h");
	  init_free_queue(&garbage_strings);
    //printf("%lu",sizeof(POKEMONDEX)/sizeof(POKEMONDEX[0]));
    #include "init.h"
    bool running = true;

    while(1) {
      Battle();
    }
    
    while(running)
    {
    //lastframestart = framestart;
    framestart = SDL_GetTicks();
         
        // Process events
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
                break;
            } else if (event.type == SDL_KEYDOWN) {
              if (event.key.keysym.sym == SDLK_RIGHT) {
                
              } else if (event.key.keysym.sym == SDLK_LEFT) {
                
              } else if (event.key.keysym.sym == SDLK_UP) {
                
              } else if (event.key.keysym.sym == SDLK_DOWN) {
                
              }
            } else {
                
            }
          
        }
      
      
        // Clear screen
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
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
    //system("clear");
    return 0;
}

SDL_Texture *initialize_texture_from_file(const char* file_name, SDL_Renderer *rend) {
    SDL_Surface *image = IMG_Load(file_name);
    SDL_Texture * image_texture = SDL_CreateTextureFromSurface(rend, image);
    SDL_FreeSurface(image);
    return image_texture;
}