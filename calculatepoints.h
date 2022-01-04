#ifndef CALCULATEPOINTS_H
#define CALCULATEPOINTS_H

#include "pieces.h"

#include <string>
#include <vector>

class CalculatePoints
{
public:
	CalculatePoints(std::vector<std::vector<Pieces*>> teamPieces);
	float getWhitePoints() {return whitePoint;}
	float getDarkPoints() {return darkPoint;}
private:
    void totalPoints();
	std::vector<std::vector<Pieces*>> teamPieces;
	float whitePoint = 0;
	float darkPoint = 0;
};

#endif // CALCULATEPOINTS_H
