void drawSelectionBox(SDL_Rect* rect) {
	SDL_Rect tempRect = {0,0,5,5};
	SourceRect.w = 5;
	SourceRect.h = 5;
	for (int i = 0;i < 4;i++) {
		SourceRect.x = (i % 2)*5;
		SourceRect.y = (i > 1)*5;
		tempRect.x = rect->x+((i % 2)*(rect->w-5));
		tempRect.y = rect->y+((i > 1)*(rect->h-5));
		SDL_RenderCopy(renderer,Corners,&SourceRect,&tempRect);
	}
	
	SDL_SetRenderDrawColor(renderer,144,164,174,255);
	SDL_RenderDrawLine(renderer,rect->x+5,rect->y,rect->x+rect->w-5,rect->y);
	SDL_SetRenderDrawColor(renderer,67,87,97,255);
	SDL_RenderDrawLine(renderer,rect->x,rect->y+2,rect->x,rect->y+rect->h-2);
	SDL_RenderDrawLine(renderer,rect->x+rect->w-1,rect->y+2,rect->x+rect->w-1,rect->y+rect->h-2);
	SDL_RenderDrawLine(renderer,rect->x+5,rect->y+rect->h-1,rect->x+rect->w-6,rect->y+rect->h-1);
	SDL_SetRenderDrawColor(renderer,229,229,229,255);
	SDL_RenderDrawLine(renderer,rect->x+5,rect->y+3,rect->x+rect->w-6,rect->y+3);
	SDL_RenderDrawLine(renderer,rect->x+5,rect->y+rect->h-4,rect->x+rect->w-6,rect->y+rect->h-4);
	SDL_RenderDrawLine(renderer,rect->x+3,rect->y+5,rect->x+3,rect->y+rect->h-6);
	SDL_RenderDrawLine(renderer,rect->x+rect->w-4,rect->y+5,rect->x+rect->w-4,rect->y+rect->h-6);
	
	SDL_SetRenderDrawColor(renderer,96,125,139,255);
	tempRect.x = rect->x+5;
	tempRect.y = rect->y+1;
	tempRect.w = rect->w-10;
	tempRect.h = 2;
	SDL_RenderFillRect(renderer,&tempRect);
	tempRect.y = rect->y+rect->h-3;
	SDL_RenderFillRect(renderer,&tempRect);
	
	tempRect.x = rect->x+1;
	tempRect.y = rect->y+5;
	tempRect.w = 2;
	tempRect.h = rect->h-10;
	SDL_RenderFillRect(renderer,&tempRect);
	tempRect.x = rect->x+rect->w-3;
	SDL_RenderFillRect(renderer,&tempRect);
	
  tempRect.x = rect->x+4;
	tempRect.y = rect->y+4;
	tempRect.w = rect->w-8;
	tempRect.h = rect->h-8;
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
	SDL_RenderFillRect(renderer,&tempRect);
}