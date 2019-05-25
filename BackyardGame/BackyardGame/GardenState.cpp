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
	//entities settings
	fence_left.setSpritePosition(50, 50);
	fence_right.setSpritePosition(745, 50);
	fence_up.setSpritePosition(50, 50);
	fence_down1.setSpritePosition(50, 300);
	fence_down2.setSpritePosition(440, 300);
	player.setSpritePosition(10, 400);

	fence_left.getSprite().setTexture(textures[9]);
	fence_right.getSprite().setTexture(textures[10]);
	fence_up.getSprite().setTexture(textures[7]);
	fence_down1.getSprite().setTexture(textures[8]);
	fence_down2.getSprite().setTexture(textures[8]);
	player.getSprite().setTexture(textures[1]);
}

GardenState::~GardenState()
{
}

void GardenState::colisionPreventEverything(const double & dt)
{
	colisionPreventing(player, fence_left, dt);
	colisionPreventing(player, fence_up, dt);
	colisionPreventing(player, fence_right, dt);
	colisionPreventing(player, fence_down1, dt);
	colisionPreventing(player, fence_down2, dt);
}

void GardenState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	this->map.update(dt); // ?
	this->player.update(dt); // works
	this->score.update(dt); 
	this->fence_left.update(dt);
	this->fence_up.update(dt);
	this->fence_right.update(dt);
	this->fence_down1.update(dt);
	this->fence_down2.update(dt);
	rotatingPlayer(player, dt);
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
	checkIfPlayerLeftGarden();
}

void GardenState::render(sf::RenderTarget * target)
{
	// the order matters
	this->map.render(this->window);
	this->fence_left.render(this->window);
	this->fence_up.render(this->window);
	this->fence_right.render(this->window);
	this->fence_down1.render(this->window);
	this->fence_down2.render(this->window);
	this->score.render(this->window);
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->player.render(this->window);
}
