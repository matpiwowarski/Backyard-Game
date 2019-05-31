#include "Soundtrack.h"

Soundtrack::Soundtrack()
{
	
}

Soundtrack & Soundtrack::getInstance()
{
	static Soundtrack instance;
	return instance;
}

void Soundtrack::PlayOutsideSoundtrack()
{
	StopPlayingSoundtrack();
	try
	{
		if (!backgroundMusic.openFromFile("../Assets/rpg-pack/soundtrack/WindlessSlopes.wav"))
		throw -1;
	}
	catch (int)
	{
		std::cout << "Problem with opening soundtrack file";
	}
	backgroundMusic.play();
	backgroundMusic.setLoop(true);
}

void Soundtrack::PlayBattleSoundtrack()
{
	StopPlayingSoundtrack();
	if (!battleMusic.openFromFile("../Assets/rpg-pack/soundtrack/The Arrival (BATTLE II).wav"))
	{
		throw "Problem with opening soundtrack file";
	}
	battleMusic.play();
	battleMusic.setLoop(true);
}

void Soundtrack::PlayScarySoundtrack()
{
	StopPlayingSoundtrack();
	if (!scaryMusic.openFromFile("../Assets/rpg-pack/soundtrack/Nocturnal Mysteries.wav"))
	{
		throw "Problem with opening soundtrack file";
	}
	scaryMusic.play();
	scaryMusic.setLoop(true);
}

bool Soundtrack::CheckIfSoundtrackIsPlayed() 
{
	if (backgroundMusic.getStatus() == 0)
		return false;
	else return true;
}

void Soundtrack::StopPlayingSoundtrack()
{
	backgroundMusic.stop();
	battleMusic.stop();
	scaryMusic.stop();
}

