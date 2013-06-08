#ifndef POS_H
#define POS_H

class Position {
public:
	int row;
	int col;
	Position();
	Position(int row, int col) { this->row = row; this->col = col; }
};

#endif