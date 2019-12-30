#include <iostream>
#include <fstream>
#include "Game.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "Level.h"
#include "Player.h"
#define FPS 10
using namespace std;
int main(int argc, char* args[])
{
	Uint32 frameTime, frameStart, delayTime = 1000.0f / FPS;	//	1000 default

	Game game;

	game.Init("GAME1007_M3_BlakeLiam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, 0);

	SDL_Surface* pTilesSurf = IMG_Load("Assets/Tiles.png");
	SDL_Surface* pPlayerSurf = IMG_Load("Assets/Player.png");

	SDL_Texture* pTilesText = SDL_CreateTextureFromSurface(game.getRenderer(), pTilesSurf);
	SDL_Texture* pPlayerText = SDL_CreateTextureFromSurface(game.getRenderer(), pPlayerSurf);

	
	SDL_FreeSurface(pTilesSurf);
	SDL_FreeSurface(pPlayerSurf);


	Level level[5] =
	{
		Level("Level1.txt", game.getRenderer(), pTilesText),
		Level("Level2.txt", game.getRenderer(), pTilesText),
		Level("Level3.txt", game.getRenderer(), pTilesText),
		Level("Level4.txt", game.getRenderer(), pTilesText),
		Level("Level5.txt", game.getRenderer(), pTilesText)
	};
	Player player(COLS / 2, ROWS / 2, game.getRenderer(), pPlayerText);



	
	while (game.Running())
	{
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < delayTime)
		{
			SDL_Delay((int)delayTime - frameTime);
		}
		game.Render(level[player.m_iCurrLvl], player);
		game.HandleEvents();
		game.Update(level[player.m_iCurrLvl], player);
	}
	game.Clean();
	return 0;
}