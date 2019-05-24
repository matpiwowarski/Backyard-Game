#include "HouseState.h"

void HouseState::checkIfPlayerLeftHouse()
{
	if (player.getPosition().x > 370 && player.getPosition().x < 450)
	{
		if (player.getPosition().y > 545)
		{
			backToBackyard = true;
		}
	}
}

HouseState::HouseState()
{
}

HouseState::HouseState(sf::RenderWindow * window): GameState(window)
{
	map.LoadHouseMap(); // load map
	player.setSpritePosition(420, 530);
	player.getSprite().setTexture(textures[1]);
	music.PlayOutsideSoundtrack();
}

HouseState::~HouseState()
{
}

void HouseState::colisionPreventEverything(const double & dt)
{
}

void HouseState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	this->map.update(dt); // ?
	this->player.update(dt); // works
	this->score.update(dt); // works
	rotatingPlayer(player, dt);
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
	checkIfPlayerLeftHouse();
}

void HouseState::render(sf::RenderTarget * target)
{
	// the order matters
	this->map.render(this->window);
	this->score.render(this->window);
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->player.render(this->window);
}
