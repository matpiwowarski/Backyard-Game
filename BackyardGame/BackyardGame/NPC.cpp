#include "NPC.h"



NPC::NPC()
{
}


NPC::~NPC()
{
}

sf::Sprite NPC::playRockPaperScissors(sf::RenderTarget * target)
{
	if (!boardTexture.loadFromFile("../Assets/board_rps.png"))
	{
		throw; // error
	}
	else
	{
		boardSprite.setTexture(boardTexture);
		boardSprite.setScale(sf::Vector2f(3.f, 3.f));
		boardSprite.setPosition(sf::Vector2f(230.f, 252.f));

		return boardSprite;
	}
}
