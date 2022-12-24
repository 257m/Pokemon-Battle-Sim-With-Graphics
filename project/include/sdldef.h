#ifndef SDL_DEF_H
#define SDL_DEF_H

#include "common.h"
#include "enumdefs.h"

#define framerate 60
#define framedelay 1000/framerate

SDL_Texture *initialize_texture_from_file(const char* file_name, SDL_Renderer *rend);
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int width;
extern int height;
extern float renderscale;
// orginal: width: 256 height: 192 background: 256x144 textbox: 256x48
// resized: 1024x768 background: 1024x576 textbox: 1024x192

extern unsigned int framestart;
extern unsigned int lastframestart;
extern unsigned int frametime;
extern unsigned int thisdraw;
extern unsigned int lastdraw;
extern unsigned int timesincelastdraw;
extern SDL_Rect DestRect;
extern SDL_Rect SourceRect;
extern SDL_Color TempColor;
extern SDL_Event event;

typedef struct {
SDL_Texture *texture;
int w;
int h;
} Texture_and_Size;

extern SDL_Texture* Pokemon_Front_Sprites [POKEMON_MAX];
extern SDL_Texture* Pokemon_Back_Sprites [POKEMON_MAX];
extern SDL_Texture* Battle_Background;
extern SDL_Texture* TextBox;
extern SDL_Texture* HpBar;
extern SDL_Texture* EnemyHpBar;
extern SDL_Texture* Indicator;
extern SDL_Texture* PartyTile;
extern SDL_Texture* Corners;
extern SDL_Texture* MoveViewPage;
extern SDL_Texture* Pokemon_Summary_Background;
extern SDL_Texture* TypeLabels;

typedef struct {
float x;
float y;
float vx;
float vy;
} Entity;

#endif // SDL_DEF_H //