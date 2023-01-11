#include "../include/common.h"
#include "../include/drawing.h"
#include "../include/sdldef.h"

unsigned char FONT_SIZES[FONT_MAX] = {12, 12, 10};

TTF_Font* fonts[FONT_MAX];
SDL_Rect glyphs[FONT_MAX][NUM_GLYPHS];
SDL_Texture* fontTextures[FONT_MAX];

SDL_Color white = {255, 255, 255, 255};

SDL_Texture* toTexture(SDL_Surface* surface, int destroySurface)
{
	SDL_Texture* texture;

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	if (destroySurface) {
		SDL_FreeSurface(surface);
	}

	return texture;
}

void InitFont(int fontType, char* filename, unsigned char Font_Size, bool Solid)
{
	SDL_Surface *surface, *text;
	SDL_Rect dest;
	int i;
	char c[2];
	SDL_Rect* g;

	memset(&glyphs[fontType], 0, sizeof(SDL_Rect) * NUM_GLYPHS);

	fonts[fontType] = TTF_OpenFont(filename, Font_Size);

	surface = SDL_CreateRGBSurface(0, FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE, 32,
								   0, 0, 0, 0xff);

	SDL_SetColorKey(surface, SDL_TRUE,
					SDL_MapRGBA(surface->format, 0, 0, 0, 0));

	dest.x = 0;
	dest.y = 0;

	for (i = ' '; i <= 'z'; i++) {
		c[0] = i;
		c[1] = 0;
		if (Solid)
			text = TTF_RenderUTF8_Solid(fonts[fontType], c, white);
		else
			text = TTF_RenderUTF8_Blended(fonts[fontType], c, white);

		TTF_SizeText(fonts[fontType], c, &dest.w, &dest.h);

		if (dest.x + dest.w >= FONT_TEXTURE_SIZE) {
			dest.x = 0;

			dest.y += dest.h + 1;

			if (dest.y + dest.h >= FONT_TEXTURE_SIZE) {
				SDL_LogMessage(
					SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_CRITICAL,
					"Out of glyph space in %dx%d font atlas texture map.",
					FONT_TEXTURE_SIZE, FONT_TEXTURE_SIZE);
				exit(1);
			}
		}

		SDL_BlitSurface(text, NULL, surface, &dest);

		g = &glyphs[fontType][i];

		g->x = dest.x;
		g->y = dest.y;
		g->w = dest.w;
		g->h = dest.h;

		SDL_FreeSurface(text);

		dest.x += dest.w;
	}

	fontTextures[fontType] = toTexture(surface, 1);
}

void InitFonts(void)
{
	InitFont(REGULAR_FONT, "fonts/pkmndp.ttf", FONT_SIZES[0], 1);
	InitFont(SECONDARY_FONT, "fonts/pkmnem.ttf", FONT_SIZES[1], 1);
	InitFont(SMALL_FONT, "fonts/pkmnems.ttf", FONT_SIZES[2], 1);
}

void drawText(char* text, int x, int y, int r, int g, int b, int fontType)
{
	int i, character;
	SDL_Rect *glyph, dest;

	SDL_SetTextureColorMod(fontTextures[fontType], r, g, b);

	i = 0;

	character = text[i++];

	while (character) {
		glyph = &glyphs[fontType][character];

		dest.x = x;
		dest.y = y;
		dest.w = glyph->w;
		dest.h = glyph->h;

		SDL_RenderCopy(renderer, fontTextures[fontType], glyph, &dest);

		x += glyph->w;

		character = text[i++];
	}
}

void drawText_Shadow(char* text, int x, int y, int r, int g, int b,
					 int fontType)
{
	int i, character;
	SDL_Rect *glyph, dest;

	SDL_SetTextureColorMod(fontTextures[fontType], 165, 165, 173);

	i = 0;

	character = text[i++];

	dest.x = x;
	dest.y = y;
	while (character) {
		glyph = &glyphs[fontType][character];

		dest.x++;
		dest.w = glyph->w;
		dest.h = glyph->h;

		SDL_RenderCopy(renderer, fontTextures[fontType], glyph, &dest);

		dest.x--;
		dest.y++;

		SDL_RenderCopy(renderer, fontTextures[fontType], glyph, &dest);

		dest.y--;

		dest.x += glyph->w;
		character = text[i++];
	}

	SDL_SetTextureColorMod(fontTextures[fontType], r, g, b);

	i = 0;

	character = text[i++];
	dest.x = x;
	while (character) {
		glyph = &glyphs[fontType][character];

		dest.w = glyph->w;
		dest.h = glyph->h;

		SDL_RenderCopy(renderer, fontTextures[fontType], glyph, &dest);

		dest.x += glyph->w;

		character = text[i++];
	}
}

void drawTextSize(char* text, int x, int y, int r, int g, int b, int fontType,
				  unsigned char TextSize)
{
	int i, character;
	SDL_Rect *glyph, dest;

	SDL_SetTextureColorMod(fontTextures[fontType], r, g, b);

	i = 0;

	character = text[i++];

	while (character) {
		glyph = &glyphs[fontType][character];

		dest.x = x;
		dest.y = y;
		dest.w = TextSize;
		dest.h = TextSize;

		SDL_RenderCopy(renderer, fontTextures[fontType], glyph, &dest);

		x += glyph->w;

		character = text[i++];
	}
}

SDL_Texture* getTextTexture(char* text, int type)
{
	SDL_Surface* surface;

	surface = TTF_RenderUTF8_Blended(fonts[type], text, white);

	return toTexture(surface, 1);
}

bool IsPrinting;

char drawScrollingText(char* text, int x, int y, int r, int g, int b,
					   int fontType, unsigned int delay)
{
	int i, character;
	static unsigned int max, start_time;
	SDL_Rect *glyph, dest;

	if (!IsPrinting) {
		IsPrinting = 1;
		max = 1;
		start_time = SDL_GetTicks();
	}
	else {
		max = ((SDL_GetTicks() - start_time)) / delay;
		max++;
	}

	SDL_SetTextureColorMod(fontTextures[fontType], r, g, b);

	i = 0;

	character = text[i++];

	while (i < max) {
		if (!character) {
			IsPrinting = 0;
			return 0;
		}

		glyph = &glyphs[fontType][character];

		dest.x = x;
		dest.y = y;
		dest.w = glyph->w;
		dest.h = glyph->h;

		SDL_RenderCopy(renderer, fontTextures[fontType], glyph, &dest);

		x += glyph->w;

		character = text[i++];
	}
	// printf("%d\n",max);
	return 1;
}