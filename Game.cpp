#include <chrono>
#include <iostream>
#include <string>
#include "Game.h"
using namespace std;
SDL_Renderer * Game::getRenderer()
{
	return m_pRenderer;
}
bool Game::Init(const char* title, int xpos, int ypos, int width,
	int height, int flags)
{
	srand((unsigned)time(NULL));
	// Attempt to initialize SDL.
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "SDL init success" << endl;
		// Init the window.
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) // Window init success.
		{
			cout << "Window creation successful" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) // Renderer init success.
			{
				cout << "renderer creation success" << endl;
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
			}
			else
			{
				cout << "renderer init fail" << endl;
				return false; // Renderer init fail.
			}
		}
		else
		{
			cout << "window init fail" << endl;
			return false; // Window init fail.
		}
		if (IMG_Init(IMG_INIT_PNG))
		{
			cout << "image init success" << endl;
		}
		else
		{
			cout << "png image init fail" << endl;
			return false; // Window init fail.
		}
		if (Mix_Init(MIX_INIT_MP3) != 0) // Mixer init success.
		{//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
			Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 8192);
			Mix_AllocateChannels(16);
		}
		else
		{
			cout << "audio init fail" << endl;
			return false; // Window init fail.
		}
		if (TTF_Init() == 0)
		{

		}
		else
		{
			cout << "ttf init fail" << endl;
			return false; // Window init fail.
		}
	}
	else
	{
		cout << "SDL init fail" << endl;
		return false; // SDL init fail.
	}
	cout << "init success" << endl;
	//	Temporary Solution
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	key = SDL_GetKeyboardState(nullptr);
}


bool Game::Running()
{
	return m_bRunning;
}

void Game::Update(Level& l, Player& p)
{
	bool moving = false;

	if (KeyDown(SDL_SCANCODE_W) && p.m_bIsAlive && !p.CheckObstacle((p.m_x / 32), (p.m_y / 32) - 1, l, p))
	{
		moving = true;
		p.MoveY(-1);
	}
	if (KeyDown(SDL_SCANCODE_S) && p.m_bIsAlive && !p.CheckObstacle((p.m_x / 32), (p.m_y / 32) + 1, l, p))
	{
		moving = true;
		p.MoveY(1);
	}
	if (KeyDown(SDL_SCANCODE_A) && p.m_bIsAlive && !p.CheckObstacle((p.m_x / 32) - 1, (p.m_y / 32), l, p))
	{
		p.m_rRenderFlip = SDL_FLIP_HORIZONTAL;
		moving = true;
		p.MoveX(-1);
	}
	if (KeyDown(SDL_SCANCODE_D) && p.m_bIsAlive && !p.CheckObstacle((p.m_x / 32) + 1, (p.m_y / 32), l, p))
	{
		p.m_rRenderFlip = SDL_FLIP_NONE;
		moving = true;
		p.MoveX(1);
	}

	if (moving)
	{
		cout << p.m_x << " " << p.m_y << endl;
		if (p.CheckHazard(l, p))
		{
			cout << "GAME OVER!" << endl;
			p.m_bIsAlive = false;
			p.m_rSrc.x = 32;
		}
		for (int i = 0; i < MAXDOORS; i++)
		{
			if (p.m_x / 32 == l.doors[i].m_xDept && p.m_y / 32 == l.doors[i].m_yDept)
			{
				cout << "Intersection with door" << endl;

				p.m_iCurrLvl = l.doors[i].m_iLevelDest;
				p.m_x = l.doors[i].m_xDest * 32;
				p.m_y = l.doors[i].m_yDest * 32;
				p.UpdateDest();
			}
		}
	}
}

void Game::HandleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		}
	}
}

void Game::Render(Level& l, Player& p)
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{		
			SDL_RenderCopy(m_pRenderer, l.map[row][col].m_pTexture, &l.map[row][col].m_rSrc, &l.map[row][col].m_rDst);
		}
	}
	SDL_RenderCopyEx(m_pRenderer, p.m_pTexture, &p.m_rSrc, &p.m_rDst, 0.0f, NULL, (p.m_bIsAlive ? p.m_rRenderFlip : SDL_FLIP_NONE));
	
	SDL_RenderPresent(m_pRenderer);
	SDL_RenderClear(m_pRenderer);

	// Stop the game after the player steps on a hazard, not before:
	if (!p.m_bIsAlive)
	{
		SDL_Delay(2000); // 2 seconds delay
		m_bRunning = false;
	}
}

void Game::Clean()
{
	cout << "cleaning game" << endl;
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	SDL_Quit();
}

bool Game::KeyDown(SDL_Scancode scancode) 
{
	if (key != nullptr)
	{
		if (key[scancode])
			return true;
		else
			return false;
	}
	return false;
}