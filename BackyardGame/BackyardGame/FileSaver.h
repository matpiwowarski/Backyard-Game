#pragma once
#include <iostream>
#include <regex>
#include <fstream>

class FileSaver
{
private:
	bool save;
	int score;
	std::string name;
public:
	FileSaver(int score);
	void askToSaveFile();
	void askForName();
	void saveFile();
};

