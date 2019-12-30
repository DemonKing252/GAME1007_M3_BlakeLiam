#pragma once
#define ROWS 24
#define COLS 32
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>
#include <fstream>
#include "Door.h"
#include "Level.h"
#include "Player.h"
using namespace std;


class Game
{
private:
	bool m_bRunning = true;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	const Uint8* key;
public:
	SDL_Renderer* getRenderer();


	bool Init(const char* title, int xpos, int ypos, int width,
		int height, int flags);
	bool Running();
	void Update(Level& l, Player& player);
	void HandleEvents();
	void Render(Level& l, Player& player);
	void Clean();
	bool KeyDown(SDL_Scancode scancode);
};

