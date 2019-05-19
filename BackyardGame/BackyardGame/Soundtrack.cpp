#include "Soundtrack.h"




Soundtrack::Soundtrack()
{
	

}


Soundtrack::~Soundtrack()
{
}



void Soundtrack::PlayOutsideSoundtrack()
{
	if (!backgroundMusic.openFromFile("../Assets/rpg-pack/soundtrack/WindlessSlopes.wav"))
	{
		throw;
	}
	backgroundMusic.play();
	backgroundMusic.setLoop(true);
}
