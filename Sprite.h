#pragma once
#include "SDL_image.h"
#include "SDL.h"
class Sprite
{
public:
	char m_cOutput;
	SDL_Rect m_rDst;
	SDL_Rect m_rSrc;
	SDL_RendererFlip m_rRenderFlip;

	SDL_Texture* m_pTexture;
	SDL_Renderer* m_pRenderer;

	void SetX(int x)
	{
		m_rDst.x = x * 32;
	}
	void SetY(int y)
	{
		m_rDst.y = y * 32;
	}

	Sprite()
	{
		m_rRenderFlip = SDL_FLIP_NONE;
		m_rDst.w = 32;
		m_rDst.h = 32;
	}

	void SetSprite(SDL_Renderer* pRenderer, SDL_Texture* pTexture)
	{
		m_pRenderer = pRenderer;
		m_pTexture = pTexture;
	}
	
};