#include "king.h"

King::King(int locationX, int locationY, char team)
{
	data.team = team;
	data.pieceName = "King";
    data.locationX = locationX;
    data.locationY = locationY;
	data.point = 100.0;
}
