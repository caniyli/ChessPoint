#ifndef ROOK_H
#define ROOK_H

#include "pieces.h"

class Rook : public Pieces
{
public:
	Rook(int locationX, int locationY, char team);
};

#endif // ROOK_H
