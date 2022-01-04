#include "rook.h"

Rook::Rook(int locationX, int locationY, char team)
{
	data.team = team;
	data.pieceName = "Rook";
    data.locationX = locationX;
    data.locationY = locationY;
	data.point = 5.0;
}
