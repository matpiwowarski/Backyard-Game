#include "FileSaver.h"

FileSaver::FileSaver(int score)
{
	this->score = score;
}

void FileSaver::askToSaveFile()
{
	
	std::string choice;
	system("CLS");
	std::cout << "Do you want to save your score? (y/n)" << std::endl;
	std::cin >> choice;
	if (choice == "yes" || choice == "y" || choice == "ye" || choice == "yea" || choice == "yep")
	{
		this->save = true;
	}
	else 
	{
		this->save = false;
	}

}

void FileSaver::askForName()
{
	if (save)
	{
		bool correctName = false;
		std::string name;
		std::regex nameTemplate("^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$");
		system("CLS");
		std::cout << "Enter your name " << std::endl;

		while (!correctName)
		{
			std::cin.clear();
			std::cin >> name;
			if (std::regex_match(name, nameTemplate))
			{
				correctName = true;
			}
			else
			{
				std::cout.clear();
				system("CLS");
				std::cout << "Enter your real name " << std::endl;
			}
		}
		this->name = name;
	}
}

void FileSaver::saveFile()
{
	if (save)
	{
		std::ofstream myfile;
		
		try
		{
			myfile.open("../../highscore.txt", std::ios_base::app);
			if (myfile.is_open())
			{
				system("CLS");
				std::cout << "Your score is saved in highscore.txt file" << std::endl;
				std::string line;				// name + score
				line = this->name + "\t \t";
				line += std::to_string(this->score);
				myfile << line << std::endl;
				myfile.close();
			}
			else
			{
				throw - 1;
			}
		}
		catch (int)
		{
			std::cout << " Problem with the file opening" << std::endl;
		}
	}
}
