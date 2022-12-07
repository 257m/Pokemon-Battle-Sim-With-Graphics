SDL_Texture *initialize_texture_from_file(const char* file_name, SDL_Renderer *rend);
extern static SDL_Window *window;
extern static SDL_Renderer *renderer;
extern static int width;
extern static int height;
extern float renderscale;
// orginal: width: 256 height: 192 background: 256x144 textbox: 256x48
// resized: 1024x768 background: 1024x576 textbox: 1024x192

extern unsigned int framestart;
extern unsigned int lastframestart;
extern unsigned int frametime;
extern unsigned int thisdraw;
extern unsigned int lastdraw;
extern unsigned int timesincelastdraw;
extern static SDL_Rect DestRect;
extern static SDL_Rect SourceRect;
extern static SDL_Color TempColor;
Sxtern SDL_Event event;

typedef struct {
SDL_Texture *texture;
int w;
int h;
} Texture_and_Size;

extern SDL_Texture* Pokemon_Front_Sprites [POKEMON_MAX];
extern SDL_Texture* Pokemon_Back_Sprites [POKEMON_MAX]=;
extern SDL_Texture* Battle_Background;
extern SDL_Texture* TextBox;
extern SDL_Texture* HpBar;
extern SDL_Texture* EnemyHpBar;
extern SDL_Texture* RetrieveBox;
extern SDL_Texture* TypePPBox;
extern SDL_Texture* Indicator;
extern SDL_Texture* MoveSelectionBox;
extern SDL_Texture* PartyTile;
extern SDL_Texture* Corners;

typedef struct {
float x;
float y;
float vx;
float vy;
} Entity;

void DisplayDie(bool eop);

void UpdateBattle();