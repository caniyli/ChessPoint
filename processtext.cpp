#include "processtext.h"

ProcessText::ProcessText()
{

}

int ProcessText::readText(std::string fileName)
{
	/* Taşların bilgileri okundu ve matris olarak kaydedildi */
	std::ifstream readFile;
	readFile.open(fileName);
	std::string line;
	std::vector<std::string> row;

	if (readFile.is_open()) {
	while (!readFile.eof()) {
		for (int i = 0; i<8 ; i++ ) {
			readFile >> line;
			row.push_back(line);
		}
		pieces.push_back(row);
		row.clear();
	}
	}else  {
		return 0;
	}
	readFile.close();
	return 1;
}

void ProcessText::writeText(std::string fileName, float darkPoints, float whitePoint)
{
	// Sonuç text dosyasına yazıldı
        existFile();
	std::ofstream outfile;

        outfile.open("../sonuçlar.txt", std::ios_base::app); // append instead of overwrite
  	outfile << fileName << "\t\t" << "Siyah: " << darkPoints << "\tBeyaz: " << whitePoint << "\n"; 
}

void ProcessText::existFile()
{
	// sonuçlar.txt dosyası yoksa istenilen formatta başlatıldı
	std::ifstream myReadFile;
        myReadFile.open("../sonuçlar.txt");
	if (myReadFile.is_open()) {
		myReadFile.close();
	}else {
		std::ofstream MyFile;
                MyFile.open("../sonuçlar.txt");
		MyFile << "Tahta Dosya Adı\t\t" << "Sonuçlar\n";
		MyFile.close();
	}
}
