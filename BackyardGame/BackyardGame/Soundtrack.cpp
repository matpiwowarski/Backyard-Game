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

void Soundtrack::StopPlayingSoundtrack()
{
	backgroundMusic.stop();
	battleMusic.stop();
}

