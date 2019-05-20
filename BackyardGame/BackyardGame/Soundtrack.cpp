#include "Soundtrack.h"




Soundtrack::Soundtrack()
{
	

}


Soundtrack::~Soundtrack()
{
}



void Soundtrack::PlayOutsideSoundtrack()
{
	backgroundMusic.stop();
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
	if (!backgroundMusic.openFromFile("../Assets/rpg-pack/soundtrack/The Arrival (BATTLE II).wav"))
	{
		throw;
	}
	backgroundMusic.play();
	backgroundMusic.setLoop(true);
}
