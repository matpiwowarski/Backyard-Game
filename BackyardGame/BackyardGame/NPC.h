#pragma once
#include "Entity.h"
class NPC : public Entity
{
private: 
	int choice;
	sf::Texture boardTexture;
	sf::Sprite boardSprite;
public:
	NPC();
	~NPC();

// methods
	sf::Sprite playRockPaperScissors(sf::RenderTarget * target);

};

