#ifndef DRAWING_H
#define DRAWING_H

void UpdateBattle();
void DisplayDie(bool eop);

enum {
	REGULAR_FONT,
	SECONDARY_FONT,
	SMALL_FONT,
	FONT_MAX,
};

#define FONT_TEXTURE_SIZE 512
extern unsigned char FONT_SIZES[FONT_MAX];
#define NUM_GLYPHS 128
extern TTF_Font *fonts[FONT_MAX];
extern SDL_Rect glyphs[FONT_MAX][NUM_GLYPHS];
extern SDL_Texture *fontTextures[FONT_MAX];

SDL_Texture *toTexture(SDL_Surface *surface, int destroySurface);
void InitFont(int fontType, char *filename,unsigned char Font_Size,bool Solid);
void InitFonts(void);
void drawText(char *text, int x, int y, int r, int g, int b, int fontType);
void drawTextSize(char *text, int x, int y, int r, int g, int b, int fontType, unsigned char TextSize);
SDL_Texture *getTextTexture(char *text, int type);
extern bool IsPrinting;
char drawScrollingText(char *text, int x, int y, int r, int g, int b, int fontType, unsigned int delay);

void drawSelectionBox(SDL_Rect* rect)

#endif // DRAWING_H //