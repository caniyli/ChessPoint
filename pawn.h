#ifndef PAWN_H
#define PAWN_H

#include "pieces.h"

class Pawn : public Pieces
{
public:
	Pawn(int locationX, int locationY, char team);
};

#endif // PAWN_H
