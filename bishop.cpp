#include "bishop.h"

Bishop::Bishop(int locationX, int locationY, char team)
{
	data.team = team;
	data.pieceName = "Bishop";
    data.locationX = locationX;
    data.locationY = locationY;
	data.point = 3.0;
}
