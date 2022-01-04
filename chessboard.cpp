#include "chessboard.h"

ChessBoard::ChessBoard(std::vector<std::vector<std::string>>  pieces)
{
	// Taş bilgileri alındı.
	this->pieces = pieces;
	divideTeams(); // Taşları renklerine göre takımlara ayıran fonksiyon.
	ScanChessBoard scan(teamPieces); // Taşların hamlelerini tarayan sınıftan obje oluşturuldu
	CalculatePoints points(teamPieces); // Toplam puanları hesaplayan sınıftan obje oluşturuldu
	darkPoint = points.getDarkPoints();
	whitePoint = points.getWhitePoints();
}

void ChessBoard::divideTeams() 
{
	//-------------------- Taşlar Renklerine göre takımlara ayrıldı -------------------
	std::vector<Pieces*>  row;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (pieces[i][j][0])
			{
			case 'a':
				row.push_back(new Knight(i, j, pieces[i][j][1]));
				break;
			case 'v':
				row.push_back(new Quen(i, j, pieces[i][j][1]));
				break;
			case 's':
				row.push_back(new King(i, j, pieces[i][j][1]));
				break;
			case 'p':
				row.push_back(new Pawn(i, j, pieces[i][j][1]));
				break;
			case 'f':
				row.push_back(new Bishop(i, j, pieces[i][j][1]));
				break;
			case 'k':
				row.push_back(new Rook(i, j, pieces[i][j][1]));
				break;
			default:
				row.push_back(nullptr);
			}
		}
		teamPieces.push_back(row);
		row.clear();
	}
}
