#pragma once
#include "Sprite.h"
class BGTile : public Sprite
{
public:
	bool m_bIsObstacle;
	bool m_bIsHazard;

	void SetBGTile(char temp)
	{
		if (temp == 'M' || temp == 'm' || temp == 'O' || temp == '=' || temp == 'B')
			m_bIsObstacle = true;
		else
			m_bIsObstacle = false;

		if (temp == 'X')
			m_bIsHazard = true;
		else
			m_bIsHazard = false;

		
		SetRect(temp);
	}
	void SetRect(char temp)
	{
		if (temp == ',')
			m_rSrc = { 0, 0, 32, 32 };
		else if (temp == ';')
			m_rSrc = { 32, 0, 32, 32 };
		else if (temp == 'M')
			m_rSrc = { 64, 0, 32, 32 };
		else if (temp == 'm')
			m_rSrc = { 96, 0, 32, 32 };
		else if (temp == '.')
			m_rSrc = { 128, 0, 32, 32 };
		else if (temp == '-')
			m_rSrc = { 160, 0, 32, 32 };
		else if (temp == '~')
			m_rSrc = { 192, 0, 32, 32 };
		else if (temp == 'X')
			m_rSrc = { 224, 0, 32, 32 };
		else if (temp == '#')
			m_rSrc = { 0, 32, 32, 32 };
		else if (temp == 'O')
			m_rSrc = { 32, 32, 32, 32 };
		else if (temp == '=')
			m_rSrc = { 64, 32, 32, 32 };
		else if (temp == 'H')
			m_rSrc = { 96, 32, 32, 32 };
		else if (temp == 'B')
			m_rSrc = { 128, 32, 32, 32 };
		else if (temp == '_')
			m_rSrc = { 160, 32, 32, 32 };
		else if (temp == 'Q')
			m_rSrc = { 192, 32, 32, 32 };
		else if (temp == 'D')
			m_rSrc = { 192, 32, 32, 32 };
		else if (temp == '%')
			m_rSrc = { 224, 32, 32, 32 };

		else
			m_rSrc = { 0, 0, 0, 0 };

	}
	
};