#include "calculatepoints.h"

CalculatePoints::CalculatePoints(std::vector<std::vector<Pieces*>> teamPieces)
{
	this->teamPieces = teamPieces;
    totalPoints();
}

void CalculatePoints::totalPoints()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(teamPieces[i][j] != nullptr){
				if(teamPieces[i][j]->data.team == 'b')
					whitePoint += teamPieces[i][j]->getPoint();
				else
					darkPoint += teamPieces[i][j]->getPoint();
			}
		}
	}
}
