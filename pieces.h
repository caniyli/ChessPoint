#ifndef PIECES_H
#define PIECES_H

#include <string>

class Pieces
{
public:
	Pieces();
	// Taşların bilgilerini tutan struct yapısı
	struct Data {
		char team;
		std::string pieceName;
		int locationX;
		int locationY;
		float point;
		bool isMarked = false;
	};
	Data data;
	// İşaretlenmeye göre puan hesabı
	float getPoint();
};

#endif // PIECES_H
