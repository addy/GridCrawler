#include "map.h"


Map::Map(int w, int h, Entity* player) {
	dungeonWalls = new bool*[h];
	for(int r = 0; r < h; r++) {
		dungeonWalls[r] = new bool[w];

		
		for(int c = 0; c < w; c++) {
			if(r == 0 || r == h-1 || c == 0 || c == w-1) dungeonWalls[r][c] = true; //set walls around outer edge;

			//read from csv file to get map walls / traps?
		}
	}



	this->player = player;
	player->move(0,0);
}



inline bool Map::isWall(Position* p) {
	return dungeonWalls[p->row][p->col];
}



inline bool Map::isWall(heading_t h, Position* p) {
	return	(h == NORTH) ? dungeonWalls[p->row-1][p->col  ] :
			(h == EAST ) ? dungeonWalls[p->row  ][p->col+1] :
			(h == SOUTH) ? dungeonWalls[p->row+1][p->col  ] :
						   dungeonWalls[p->row  ][p->col-1] ;
			
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

