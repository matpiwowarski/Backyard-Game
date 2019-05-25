#include "Soundtrack.h"




Soundtrack::Soundtrack()
{
	

}


Soundtrack::~Soundtrack()
{
}



void Soundtrack::PlayOutsideSoundtrack()
{
	battleMusic.stop();
	if (!backgroundMusic.openFromFile("../Assets/rpg-pack/soundtrack/WindlessSlopes.wav"))
	{
		throw;
	}
	backgroundMusic.play();
	backgroundMusic.setLoop(true);
}

void Soundtrack::PlayBattleSoundtrack()
{
	backgroundMusic.stop();
	if (!battleMusic.openFromFile("../Assets/rpg-pack/soundtrack/The Arrival (BATTLE II).wav"))
	{
		throw;
	}
	battleMusic.play();
	battleMusic.setLoop(true);
}

bool Soundtrack::CheckIfSoundtrackIsPlayed() 
{
	if (backgroundMusic.getStatus() == 0)
		return false;
	else return true;
}

void Soundtrack::StopPlayingSoundtrack()
{
	backgroundMusic.pause();
	battleMusic.stop();
}

