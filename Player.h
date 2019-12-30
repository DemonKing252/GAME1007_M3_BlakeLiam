#pragma once
#include "LOTile.h"
class Player : public LOTile
{
public:
	bool m_bIsAlive;
	int m_iCurrLvl;

	Player(int x, int y, SDL_Renderer* pRenderer, SDL_Texture* pTexture) : LOTile(x, y)
	{
		SetX(x);
		SetY(y);
		m_pRenderer = pRenderer;
		m_pTexture = pTexture;
		m_rSrc = { 0, 0, 32, 32 };
		m_bIsAlive = true;
		m_iCurrLvl = 0;
		//cout << m_rDst.x << " " << m_rDst.y << endl;
	}
	void UpdateDest()
	{
		m_rDst.x = m_x;
		m_rDst.y = m_y;
	}
	void MoveX(int x)
	{
		m_x += x * 32;
		UpdateDest();
	}
	void MoveY(int y)
	{
		m_y += y * 32;
		UpdateDest();
	}
	bool CheckHazard(Level& l, Player& p)
	{
		if (!l.map[p.m_y / 32][p.m_x / 32].m_bIsHazard)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool CheckObstacle(int x, int y, Level& l, Player& p)
	{
		if (!l.map[y][x].m_bIsObstacle)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};