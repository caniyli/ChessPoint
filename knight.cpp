#include "knight.h"

Knight::Knight(int locationX, int locationY, char team)
{
	data.team = team;
	data.pieceName = "Knight";
    data.locationX = locationX;
    data.locationY = locationY;
	data.point = 3.0;
}
