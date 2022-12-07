static SDL_Window *window;
static SDL_Renderer *renderer;
static int width = 256;
static int height = 192;
float renderscale = 3;
// orginal: width: 256 height: 192 background: 256x144 textbox: 256x48
// resized: 1024x768 background: 1024x576 textbox: 1024x192

unsigned int framestart;
unsigned int lastframestart;
unsigned int frametime;
unsigned int thisdraw;
unsigned int lastdraw;
unsigned int timesincelastdraw;
static SDL_Rect DestRect;
static SDL_Rect SourceRect;
static SDL_Color TempColor;
SDL_Event event;

typedef struct {
SDL_Texture *texture;
int w;
int h;
} Texture_and_Size;

SDL_Texture* Pokemon_Front_Sprites [POKEMON_MAX] = {NULL,NULL};

SDL_Texture* Pokemon_Back_Sprites [POKEMON_MAX] = {NULL,NULL};
SDL_Texture* Battle_Background;
SDL_Texture* TextBox;
SDL_Texture* HpBar;
SDL_Texture* EnemyHpBar;
SDL_Texture* RetrieveBox;
SDL_Texture* TypePPBox;
SDL_Texture* Indicator;
SDL_Texture* MoveSelectionBox;
SDL_Texture* PartyTile;
SDL_Texture* Corners;