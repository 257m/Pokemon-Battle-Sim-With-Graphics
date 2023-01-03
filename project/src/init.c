#include "../include/drawing.h"
#include "../include/enumdefs.h"
#include "../include/queue.h"
#include "../include/sdldef.h"

void InitSDL()
{
	// Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);

	// Create a SDL window
	window = SDL_CreateWindow("Pokemon With Graphics", SDL_WINDOWPOS_UNDEFINED,
							  SDL_WINDOWPOS_UNDEFINED, width * renderscale,
							  height * renderscale,
							  SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	// Create a renderer (accelerated and in sync with the display refresh rate)
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderSetScale(renderer, renderscale, renderscale);

	// Initialize support for loading PNG and JPEG images
	// IMG_INIT(IMG_INIT_JPG | IMG_INIT_PNG);
	char ImagesText[64] = "\0";
	for (int i = 0; i < POKEMON_MAX; i++) {
		sprintf(ImagesText, "Images/PokemonFrontSprites/%d.png", i);
		Pokemon_Front_Sprites[i] =
			initialize_texture_from_file(ImagesText, renderer);
	}

	for (int i = 0; i < POKEMON_MAX; i++) {
		sprintf(ImagesText, "Images/PokemonBackSprites/%d.png", i);
		Pokemon_Back_Sprites[i] =
			initialize_texture_from_file(ImagesText, renderer);
	}

	Battle_Background =
		initialize_texture_from_file("Images/BattleBackground.png", renderer);
	TextBox = initialize_texture_from_file("Images/TextBox.png", renderer);
	HpBar = initialize_texture_from_file("Images/HpBar.png", renderer);
	EnemyHpBar =
		initialize_texture_from_file("Images/EnemyHpBar.png", renderer);
	Indicator = initialize_texture_from_file("Images/Indicator.png", renderer);
	PartyTile = initialize_texture_from_file("Images/PartyTile.png", renderer);
	Corners = initialize_texture_from_file("Images/Corners.png", renderer);
	MoveViewPage = initialize_texture_from_file(
		"Images/BW_Summary/Graphics/Pictures/Summary/bg_4_B2W2.png", renderer);
	Pokemon_Summary_Background = initialize_texture_from_file(
		"Images/BW_Summary/Graphics/Pictures/Summary/background.png", renderer);
	Pokemon_Summary_General = initialize_texture_from_file(
		"Images/BW_Summary/Graphics/Pictures/Summary/bg_1_B2W2.png", renderer);
	TypeLabels =
		initialize_texture_from_file("Images/typelabels.png", renderer);

	TTF_Init();
	InitFonts();
}