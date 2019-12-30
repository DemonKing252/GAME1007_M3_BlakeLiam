#pragma once
#include "Door.h"
#include "BGTile.h"
#include <string>
#include <fstream>
#define ROWS 24
#define COLS 32
#define MAXDOORS 3
using namespace std;
class Level
{
public:
	int m_iNumDoors = 0;

	string m_sLvlName;

	BGTile map[ROWS][COLS];
	Door doors[MAXDOORS];
	int currDoor = 0;
	Level(string pName, SDL_Renderer* pRenderer, SDL_Texture* pTexture)
	{
		ifstream file;
		file.open(pName);
		char temp;
		m_sLvlName = pName;
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				file >> temp;
				//cout << temp << " ";
				if (temp == 'Q')
				{
					int destX, destY, destLvl;
					// Add door
					file >> destLvl >> destX >> destY;


					map[row][col].SetSprite(pRenderer, pTexture);
					map[row][col].SetBGTile(temp);
					map[row][col].SetX(col);
					map[row][col].SetY(row);
					
					if (currDoor < MAXDOORS)
					{
						doors[currDoor++].AddDoor(col, row, destX, destY, destLvl);
						cout << "Door # " << currDoor - 1 << " " << doors[currDoor - 1].m_xDept
							<< " " << doors[currDoor - 1].m_yDept
							<< " " << doors[currDoor - 1].m_xDest
							<< " " << doors[currDoor - 1].m_yDest
							<< ", Level dest: " << doors[currDoor - 1].m_iLevelDest << endl;
					}
						

				}
				else
				{

					map[row][col].SetSprite(pRenderer, pTexture);
					map[row][col].SetBGTile(temp);
					map[row][col].SetX(col);
					map[row][col].SetY(row);
				}
			}
			//cout << endl;
		}
	}

};