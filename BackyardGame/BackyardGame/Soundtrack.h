#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"

class Soundtrack
{
protected:
sf::Music backgroundMusic;

public:
	void PlayOutsideSoundtrack();
	void PlayBattleSoundtrack();
	Soundtrack();
	~Soundtrack();
};

