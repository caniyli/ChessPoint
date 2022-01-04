#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>
#include <vector>

#include "quen.h"
#include "king.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "pieces.h"
#include "knight.h"
#include "calculatepoints.h"
#include "scanchessboard.h"

class ChessBoard
{
public:
	ChessBoard(std::vector<std::vector<std::string>>  pieces);
	float getWhitePoint() {return whitePoint;}
	float getDarkPoint() {return darkPoint;}
private:
	std::vector<std::vector<std::string> > pieces;
	std::vector<std::vector<Pieces*>> teamPieces;
	void divideTeams();
	float whitePoint;
	float darkPoint;
};

#endif // CHESSBOARD_H
