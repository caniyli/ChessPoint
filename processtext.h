#ifndef PROCESSTEXT_H
#define PROCESSTEXT_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <ios>

class ProcessText
{
public:
	ProcessText();
	int readText(std::string fileName);
	void writeText(std::string fileName, float darkPoints, float whitePoint);
	std::vector<std::vector<std::string>> getpieces() {return pieces;}
private:
	std::vector<std::vector<std::string>>  pieces;
	void existFile();
};

#endif // PROCESSTEXT_H
