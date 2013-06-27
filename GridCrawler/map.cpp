#include "map.h"


Map::Map(int w, int h, Entity* player, map_locale_t mapType ) {
	dungeonWalls = new bool*[h];
	width = w;
	height = h;
	for(int r = 0; r < h; r++) {
		dungeonWalls[r] = new bool[w];

		
		for(int c = 0; c < w; c++) {
			dungeonWalls[r][c] = false;
			//read from csv file to get map walls / traps?
		}
	}



	//load textures based on mapType
	textures = (sf::Texture *) malloc(sizeof(sf::Texture)*DUNGEON_TEXTURES_LIST_SIZE);

	for(int i = 0; i < DUNGEON_TEXTURES_LIST_SIZE; i++) {
			if (!textures[i].loadFromFile(DUNGEON_TEXTURES_LIST[i]))
			{
				//ERROR!
			}
	}


	this->player = player;
	player->move(0,0);
}

Map::~Map(void) {
	for(int r = 0; r < height; r++) delete[] dungeonWalls[r];
	delete[] dungeonWalls;
	delete textures;
}



inline bool Map::isWall(Position* p) {
	return (p->col < width  && p->col >= 0 &&
			p->row < height && p->col >= 0) ? dungeonWalls[p->row][p->col] : true;
}

inline bool Map::isWall(int r, int c) {
	return (c < width  && c >= 0 &&
			r < height && r >= 0) ? dungeonWalls[r][c] : true;
}

inline bool Map::isWall(heading_t h, Position* p) {
	return	(h == NORTH) ? isWall(p->row-1, p->col  ) :
			(h == EAST ) ? isWall(p->row  , p->col+1) :
			(h == SOUTH) ? isWall(p->row+1, p->col  ) :
			(h == WEST ) ? isWall(p->row  , p->col-1) : true;			
}


void Map::handleMonsterMovement(void) {
	for(unsigned int i = 0; i < monsters.size(); i++) {
		if(rand() % 100 > 25) //25% (ish) of monsters move
		{
			switch(rand() % 4 + 1) {  //choose a random heading
				case 1:
					if(!isWall(NORTH, monsters[i]->getPos())) monsters[i]->moveNorth();
					break;
				case 2:
					if(!isWall(EAST, monsters[i]->getPos())) monsters[i]->moveEast();
					break;
				case 3:
					if(!isWall(SOUTH, monsters[i]->getPos())) monsters[i]->moveSouth();
					break;
				case 4:
					if(!isWall(WEST, monsters[i]->getPos())) monsters[i]->moveWest();
					break;
			}
		}
	}
}

