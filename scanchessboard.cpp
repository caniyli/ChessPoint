#include "scanchessboard.h"

ScanChessBoard::ScanChessBoard(std::vector<std::vector<Pieces*>> teamPieces)
{
	this->teamPieces = teamPieces;
	scan(); // Tahta üzerinde bulunan tüm taşları tarayan fonksiyon
}

void ScanChessBoard::scan()
{
	// ------------------ Taşlar tarandı isimlerine göre  yapabilecekleri hamlelere yönlendirildi -------------
	for (int i = 0; i<teamPieces.size() ;i++) {
		for (int j = 0; j<teamPieces[i].size() ;j++) {
			if(teamPieces[i][j] != nullptr) {
				if(teamPieces[i][j]->data.pieceName == "Quen") {  // Vezir için;
					scanHorizontal(teamPieces[i][j]->data.team,  // Yatay hareket tarandı
								   teamPieces[i][j]->data.locationX,
								   teamPieces[i][j]->data.locationY);
					scanVertical(teamPieces[i][j]->data.team,    // Dikey hareket tarandı
								   teamPieces[i][j]->data.locationX,
								   teamPieces[i][j]->data.locationY);
					scanDiagonal(teamPieces[i][j]->data.team,    // Çarpraz hareket tarandı
								   teamPieces[i][j]->data.locationX,
								   teamPieces[i][j]->data.locationY);
				} else if(teamPieces[i][j]->data.pieceName == "Knight") {  // At için;
					scanKnights(teamPieces[i][j]->data.team,   // Atın yaptığı L hareket tarandı
								teamPieces[i][j]->data.locationX,
								teamPieces[i][j]->data.locationY);
				} else if(teamPieces[i][j]->data.pieceName == "Pawn") { // Piyon için;
					scanPawns(teamPieces[i][j]->data.team,	// Piyonun çarpraz hareketi tarandı
							  teamPieces[i][j]->data.locationX,
							  teamPieces[i][j]->data.locationY);
				}
			}
		}
	}
}

void ScanChessBoard::scanVertical(char team, int x, int y)
{
	// Dikeyde aşağı hareket kodları
	for (int i = (x + 1); i < 8; i++) {
		if(teamPieces[i][y] != nullptr) {
			if(teamPieces[i][y]->data.team == team)
				break;
			else {
				teamPieces[i][y]->data.isMarked = true;
				break;
			}
		}
	}
	// Dikeyde yukarı hareket kodları
	for (int i = (x - 1); i >= 0; i--) {
		if(teamPieces[i][y] != nullptr) {
			if(teamPieces[i][y]->data.team == team)
				break;
			else {
				teamPieces[i][y]->data.isMarked = true;
				break;
			}
		}
	}
}

void ScanChessBoard::scanHorizontal(char team, int x, int y)
{
	// Yatayda sağa hareket kodları
	for (int i = (y + 1); i < 8; i++) {
		if(teamPieces[x][i] != nullptr) {
			if(teamPieces[x][i]->data.team == team)
				break;
			else {
				teamPieces[x][i]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
				break;
			}
		}
	}
	// Yatayda sola hareket kodları
	for (int i = (y - 1); i >= 0; i--) {
		if(teamPieces[x][i] != nullptr) {
			if(teamPieces[x][i]->data.team == team)
				break;
			else {
				teamPieces[x][i]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
				break;
			}
		}
	}
}

void ScanChessBoard::scanDiagonal(char team, int x, int y)
{
	// Sağ aşağı çarpraz hareket kodları
	for (int i = 1; i < 8; i++){
		if (x + i > 7 || y + i > 7)
			break;
		if(teamPieces[x + i][y + i] != nullptr) {
			if(teamPieces[x + i][y + i]->data.team == team)
				break;
			else {
				teamPieces[x+i][y+i]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
				break;
			}
		}
	}
	// Sol aşağı çarpraz hareket kodları
	for (int i = 1; i < 8; i++){
		if (x + i > 7 || y - i < 0)
			break;
		if(teamPieces[x + i][y -i ] != nullptr) {
			if(teamPieces[x + i][y - i]->data.team == team)
				break;
			else {
				teamPieces[x + i][y - i]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
				break;
			}
		}
	}
	// Sağ yukarı çarpraz hareket kodları
	for (int i = 1; i < 8; i++){
		if (x - i < 0 || y + i > 7)
			break;
		if(teamPieces[x - i][y + i ] != nullptr) {
			if(teamPieces[x - i][y + i]->data.team == team)
				break;
			else {
				teamPieces[x - i][y + i]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
				break;
			}
		}
	}
	// Sol yukarı çarpraz hareket kodları
	for (int i = 1; i < 8; i++){
		if (x - i < 0 || y - i < 0)
			break;
		if(teamPieces[x - i][y - i ] != nullptr) {
			if(teamPieces[x - i][y - i]->data.team == team)
				break;
			else {
				teamPieces[x - i][y - i]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
				break;
			}
		}
	}
}

void ScanChessBoard::scanKnights(char team, int x, int y)
{
	// Yukarı L hareket kodları
	if(x + 2 < 8) {
		if (y + 1 < 8 && teamPieces[x + 2][y + 1 ] != nullptr && teamPieces[x + 2][y + 1 ]->data.team != team) {
			teamPieces[x + 2][y + 1 ]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
		if (y - 1 > 0 && teamPieces[x + 2][y - 1 ] != nullptr && teamPieces[x + 2][y - 1 ]->data.team != team) {
			teamPieces[x + 2][y - 1 ]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
	}
	// Aşağı L hareket kodları
	if(x - 2 >= 0) {
		if (y + 1 < 8 && teamPieces[x - 2][y + 1 ] != nullptr && teamPieces[x - 2][y + 1 ]->data.team != team) {
			teamPieces[x - 2][y + 1 ]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
		if (y - 1 > 0 && teamPieces[x - 2][y - 1 ] != nullptr && teamPieces[x - 2][y - 1 ]->data.team != team) {
			teamPieces[x - 2][y - 1 ]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
	}
	// Sağa L hareket kodları
	if(y + 2 < 8) {
		if (x + 1 < 8 && teamPieces[x + 1][y + 2 ] != nullptr && teamPieces[x + 1][y + 2]->data.team != team) {
			teamPieces[x + 1][y + 2]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
		if (x - 1 > 0 && teamPieces[x - 1][y + 2] != nullptr && teamPieces[x - 1][y + 2]->data.team != team) {
			teamPieces[x - 1][y + 2]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
	}
	// Sola L hareket kodları
	if(y - 2 >= 0) {
		if (x + 1 < 8 && teamPieces[x + 1][y - 2 ] != nullptr && teamPieces[x + 1][y - 2]->data.team != team) {
			teamPieces[x + 1][y - 2]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
		if (x - 1 > 0 && teamPieces[x - 1][y - 2] != nullptr && teamPieces[x - 1][y - 2]->data.team != team) {
			teamPieces[x - 1][y - 2]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		}
	}
}

void ScanChessBoard::scanPawns(char team, int x, int y)
{
	// Beyaz takım piyonu için yukarı hareket kodları
	if(team == 'b') {
		if (teamPieces[x - 1][y + 1] != nullptr && y + 1 < 8 && teamPieces[x - 1][y + 1]->data.team != team)
			teamPieces[x - 1][y + 1]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		if (teamPieces[x - 1][y - 1] != nullptr && y - 1 > -1 && teamPieces[x - 1][y - 1]->data.team != team)
			teamPieces[x - 1][y - 1]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
	}
	// Siyah takım piyonu için aşağı hareket kodları
	if(team == 's' && y + 1 < 8 && y - 1 > -1)
	{
		if (teamPieces[x + 1][y + 1] != nullptr && y + 1 < 8 && teamPieces[x + 1][y + 1]->data.team != team)
			teamPieces[x + 1][y + 1]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
		if (teamPieces[x + 1][y - 1] != nullptr && y - 1 > -1 &&teamPieces[x + 1][y - 1]->data.team != team)
			teamPieces[x + 1][y - 1]->data.isMarked = true;  // Eğer Hareket alanında karşı takımdan taş varsa işaretler.
	}
}
