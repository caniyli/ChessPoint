#ifndef SCANCHESSBOARD_H
#define SCANCHESSBOARD_H

#include "pieces.h"
#include <string>
#include <vector>

class ScanChessBoard
{
public:
	ScanChessBoard(std::vector<std::vector<Pieces*>> teamPieces);
private:
	std::vector<std::vector<Pieces*>> teamPieces;
	void scan();
	void scanHorizontal(char team, int x, int y);
	void scanVertical(char team, int x, int y);
	void scanDiagonal(char team, int x, int y);
	void scanKnights(char team, int x, int y);
	void scanPawns(char team, int x, int y);
};

#endif // SCANCHESSBOARD_H
