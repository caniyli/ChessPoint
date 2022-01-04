#include <iostream>
#include "processtext.h"
#include "pieces.h"
#include "pawn.h"
#include "chessboard.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Gerekli argumanı girerek istediğiniz dosyayı okuyabilirsiniz
	// Örnek çalıştırma komutu ./ChessProject board1.txt
	std::string fileName = std::string(argv[1]);

	ProcessText processText;
	if (!processText.readText("../" + fileName))
	{
		cout << "Dosya açılamadı, program sonlandı" << endl;
		return 0;
	}
	ChessBoard board(processText.getpieces());
	processText.writeText(fileName, board.getDarkPoint(), board.getWhitePoint());
	return 0;
}
