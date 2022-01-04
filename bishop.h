#ifndef BISHOP_H
#define BISHOP_H

#include "pieces.h"

class Bishop : public Pieces
{
public:
	Bishop(int locationX, int locationY, char team);
};

#endif // BISHOP_H
