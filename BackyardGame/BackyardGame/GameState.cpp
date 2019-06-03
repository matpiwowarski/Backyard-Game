#include "GameState.h"

GameState::GameState()
{

}

GameState::GameState(sf::RenderWindow * window): State(window)
{

}

GameState::~GameState()
{
}

void GameState::endState()
{

}

void GameState::blockPlayer()
{
	player.block();
}

void GameState::unblockPlayer()
{
	player.unblock();
}

void GameState::rotatingPlayer(Player & player, const double& dt)
{
	if (!player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player.getSprite().setTexture(textures[2]);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player.getSprite().setTexture(textures[1]);
	}			
}

void GameState::updateKeybinds(const double & dt)
{
	this->checkQuit();
}

