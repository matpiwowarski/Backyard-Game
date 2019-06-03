#pragma once
#include "Soundtrack.h"
#include <iostream>
#include <regex>
#include <fstream>

class FileSaver
{
private:
	bool save;			// true => save file
	int score;			// score to save
	std::string name;	// player name
public:
	FileSaver(int score);
	void askToSaveFile();
	void askForName();
	void saveFile();
};

