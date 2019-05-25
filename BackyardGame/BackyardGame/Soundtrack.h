#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"

class Soundtrack
{
protected:
sf::Music backgroundMusic;
sf::Music battleMusic;
public:
	void PlayOutsideSoundtrack();
	void PlayBattleSoundtrack();
	void StopPlayingSoundtrack();
	Soundtrack();
	~Soundtrack();
};

