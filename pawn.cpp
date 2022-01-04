#include "pawn.h"

Pawn::Pawn(int locationX, int locationY, char team)
{
	data.team = team;
	data.pieceName = "Pawn";
	data.locationX = locationX;
	data.locationY = locationY;
	data.point = 1.0;
}
