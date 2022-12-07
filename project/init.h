// Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    //system("clear");
    //printf("\e[?25l");
    // Create a SDL window
    window = SDL_CreateWindow("Pokemon With Graphics", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width*renderscale, height*renderscale, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    // Create a renderer (accelerated and in sync with the display refresh rate)
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderSetScale(renderer,renderscale,renderscale);

    // Initialize support for loading PNG and JPEG images
    //IMG_INIT(IMG_INIT_JPG | IMG_INIT_PNG);
    free_pointers[0] = malloc(36);
    for (int i = 0;i < POKEMON_MAX;i++) {
			sprintf(free_pointers[0],"Images/PokemonFrontSprites/%d.png",i);
			Pokemon_Front_Sprites[i] = initialize_texture_from_file(free_pointers[0],renderer);
    }
    
    for (int i = 0;i < POKEMON_MAX;i++) {
      sprintf(free_pointers[0],"Images/PokemonBackSprites/%d.png",i);
			Pokemon_Back_Sprites[i] = initialize_texture_from_file(free_pointers[0],renderer);
    }
    free(free_pointers[0]);

    
  Battle_Background = initialize_texture_from_file("Images/BattleBackground.png",renderer);
  TextBox = initialize_texture_from_file("Images/TextBox.png",renderer);
  HpBar = initialize_texture_from_file("Images/HpBar.png",renderer);
  EnemyHpBar = initialize_texture_from_file("Images/EnemyHpBar.png",renderer);
	RetrieveBox = initialize_texture_from_file("Images/RetrieveBox.png",renderer);
	Indicator = initialize_texture_from_file("Images/Indicator.png",renderer);
	TypePPBox = initialize_texture_from_file("Images/TypePPBox.png",renderer);
	MoveSelectionBox = initialize_texture_from_file("Images/MoveSelectionBox.png",renderer);
  PartyTile = initialize_texture_from_file("Images/PartyTile.png",renderer);
	Corners = initialize_texture_from_file("Images/Corners.png",renderer);

	TTF_Init();
	InitFonts();