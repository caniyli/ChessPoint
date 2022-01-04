#ifndef KING_H
#define KING_H

#include "pieces.h"

class King : public Pieces
{
public:
	King(int locationX, int locationY, char team);
};

#endif // KING_H
