
#ifndef SDLDISPLAY_HEADER
#define SDLDISPLAY_HEADER

#include "Chip8.h"
#include <SDL2/SDL.h>

struct DisplaySDL {

	int width, height;

	unsigned char keys[16];

	bool errored = false;
	bool quit = false;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* gfxSurface = NULL;
	SDL_Surface* gfxSurfaceStreached = NULL;

	SDL_Event event;

	const int FPS_LIMIT = 60;
	const int TICKS_PER_FRAME = 1000 / FPS_LIMIT;
	int frames = 0;
	int startTicks;
	int displayFPS = 0;

	int scale = 10;

	DisplaySDL(const char* title, int width, int height);
	~DisplaySDL();

	virtual void drawGridAt(const unsigned char* grid, int width, int height, unsigned char multiplier, int drawX, int drawY, int drawWidth, int drawHeight, int smoothOn = 0xFF, int smoothOff = 0xFF);
	virtual void draw();
	virtual void update();

};

#endif
