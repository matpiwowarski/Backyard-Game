#include "GardenState.h"



void GardenState::checkIfPlayerLeftGarden()
{
	if (player.getPosition().x < 5) 
	{
		music.StopPlayingSoundtrack();
		backToBackyard = true;
	}
}

GardenState::GardenState()
{
}


GardenState::GardenState(sf::RenderWindow * window) : GameState(window)
{
	map.LoadGardenMap(); // load map
	player.setSpritePosition(10, 530);
	player.getSprite().setTexture(textures[1]);
	music.PlayOutsideSoundtrack();
}

GardenState::~GardenState()
{
}

void GardenState::colisionPreventEverything(const double & dt)
{
}

void GardenState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	this->map.update(dt); // ?
	this->player.update(dt); // works
	this->score.update(dt); // works
	rotatingPlayer(player, dt);
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
	checkIfPlayerLeftGarden();
}

void GardenState::render(sf::RenderTarget * target)
{
	// the order matters
	this->map.render(this->window);
	this->score.render(this->window);
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->player.render(this->window);
}
