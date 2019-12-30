#pragma once
#include "Sprite.h"
class LOTile : public Sprite
{
public:
	int m_x;
	int m_y;
	LOTile()
	{
		
	}
	LOTile(int x, int y)
	{
		SetX(x);
		SetY(y);
		m_x = x * 32;
		m_y = y * 32;
	}
	
};
