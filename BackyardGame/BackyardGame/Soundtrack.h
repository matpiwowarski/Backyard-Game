#pragma once
#include <SFML/Audio.hpp>
#include "Entity.h"

// Singleton pattern

class Soundtrack
{
private:
	Soundtrack();
protected:
sf::Music backgroundMusic;
sf::Music battleMusic;
sf::Music scaryMusic;

public:
	static Soundtrack & getInstance();
	void PlayOutsideSoundtrack();
	void PlayBattleSoundtrack();
	void PlayScarySoundtrack();
	bool CheckIfSoundtrackIsPlayed();
	void StopPlayingSoundtrack();

};

