#include "Map.h"
#include "TextureManager.h"
#include <SDL.h>
#include "Player.h"
#include <iostream>
#include <fstream>
#include "Game.h"
#include <stdlib.h>

int lvl1[23][45] = {

{60,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,58,59 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,22,49, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1,18, 1, 1, 1, 5, 9, 1, 1, 1, 1, 1,18,18,18,18, 1, 1, 1,18,18,18,18,18,18, 1, 1, 1, 1, 1,18,18,18,18,18,18,18, 1, 1, 1, 1, 1,51 },
{57, 1, 1,18,18, 1, 1,22,49, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 9, 1, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 1, 5, 9, 1, 1, 1,51 },
{57, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 5, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,22,49, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,22,49, 1, 1, 1,51 },
{57, 1, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 1,22,49, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1,18, 1, 1,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 5, 9, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18,18, 1,18,18, 1, 1, 1, 1,22,49, 1, 1, 1, 1, 1,18, 1, 1, 1,51 },
{57, 1, 1, 1, 1,22,49, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18,18,18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1,18, 1, 1, 1, 1, 1, 1, 5, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,18, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1,18, 1, 1, 1, 1, 1, 1,22,49, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{57, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,51 },
{63,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,53,64 }

};

Map::Map(SDL_Renderer* renderer) : renderer(renderer)
{
	for (int id = 0; id < 65; ++id)
	{
		Tiles[id] = new Tile(id, renderer);
		Tiles[id]->init();
	}

	LoadMap("assets/level1.txt");

}

Map::~Map()
{

}

void Map::LoadMap(const char *file)
{
	int tileType;
	std::ifstream mapFile;
	mapFile.open("assets/level1.txt");

	if (mapFile.is_open())
	{
		for (int row = 0; row < 23; row++)
		{
			for (int column = 0; column < 45; column++)
			{
				if (mapFile >> tileType)
				{
					map[row][column] = tileType;
				}
			}
		}
		mapFile.close();
	}
}

void Map::update()
{
	for (int row = 0; row < 23; row++)
	{
		for (int column = 0; column < 45; column++)
		{
			int type = 0;
			type = map[row][column];

			if (Tiles[type])
			{
				Tiles[type]->move.setPositionx(column * 64 - Game::camera.x);
				Tiles[type]->move.setPositiony(row * 64 - Game::camera.y);
				//Move tiles here




				//__________________
				Tiles[type]->update();


				DrawTiles(row, column);
			}
		}
	}
	std::cout << std::endl;
}

void Map::DrawTiles(int xpos, int ypos)
{
	int type;
	type = map[xpos][ypos];

	Tiles[type]->draw();

}

