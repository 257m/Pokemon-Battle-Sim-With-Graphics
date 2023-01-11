#include "../include/common.h"
#include "../include/enumdefs.h"

SDL_Window* window;
SDL_Renderer* renderer;
int width = 256;
int height = 192;
float renderscale = 3;
// orginal: width: 256 height: 192 background: 256x144 textbox: 256x48
// resized: 1024x768 background: 1024x576 textbox: 1024x192

unsigned int framestart;
unsigned int lastframestart;
unsigned int frametime;
unsigned int thisdraw;
unsigned int lastdraw;
unsigned int timesincelastdraw;
SDL_Rect DestRect;
SDL_Rect SourceRect;
SDL_Color TempColor;
SDL_Event event;

SDL_Texture* Pokemon_Front_Sprites[POKEMON_MAX] = {NULL, NULL};

SDL_Texture* Pokemon_Back_Sprites[POKEMON_MAX] = {NULL, NULL};
SDL_Texture* Battle_Background;
SDL_Texture* TextBox;
SDL_Texture* HpBar;
SDL_Texture* EnemyHpBar;
SDL_Texture* Indicator;
SDL_Texture* PartyTile;
SDL_Texture* Corners;
SDL_Texture* MoveViewPage;
SDL_Texture* Pokemon_Summary_Background;
SDL_Texture* TypeLabels;
SDL_Texture* Pokemon_Summary_General;
SDL_Texture* CategoryIcons;

SDL_Texture* initialize_texture_from_file(const char* file_name,
										  SDL_Renderer* rend)
{
	SDL_Surface* image = IMG_Load(file_name);
	SDL_Texture* image_texture = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	return image_texture;
}