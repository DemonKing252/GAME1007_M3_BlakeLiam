#pragma once
#include "LOTile.h"
class Door : public LOTile
{
public:
	int m_xDept;
	int m_yDept;
	int m_xDest;
	int m_yDest;

	int m_iLevelDest;

	Door()
	{
		m_cOutput = 'D';
	}
	void AddDoor(int x, int y, int dX, int dY, int levelDest)
	{
		m_xDept = x;
		m_yDept = y;
		m_xDest = dX;
		m_yDest = dY;
		m_iLevelDest = levelDest;
	}
};