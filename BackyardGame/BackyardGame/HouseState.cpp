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

void HouseState::checkArmWrestlingAction()
{
}

HouseState::HouseState()
{
}

HouseState::HouseState(sf::RenderWindow * window): GameState(window)
{
	map.LoadHouseMap(); // load map
	player.setSpritePosition(420, 530);
	player.getSprite().setTexture(textures[1]);

	skeleton.setSpritePosition(200, 100);
	skeleton.getSprite().setTexture(textures[15]);
	skeleton.getSprite().setScale(sf::Vector2f(4.f, 4.f));

	music.PlayScarySoundtrack();
}

HouseState::~HouseState()
{
}

void HouseState::checkMovementLimits(const double & dt)
{
	if (this->player.getPosition().x <= 30)
		this->player.move(dt, 1.f, 0.f);
	if (this->player.getPosition().x >= 738)
		this->player.move(dt, -1.f, 0.f);
	if (this->player.getPosition().y <= 30)
		this->player.move(dt, 0.f, 1.f);
	if (this->player.getPosition().y >= 555)
		this->player.move(dt, 0.f, -1.f);
}

void HouseState::colisionPreventEverything(const double & dt)
{
	colisionPreventing(player, skeleton, dt);
}

void HouseState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	this->checkMovementLimits(dt); // works
	this->map.update(dt); // ?
	this->player.update(dt); // works
	this->score.update(dt); // works
	this->skeleton.update(dt); // ?
	rotatingPlayer(player, dt);
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
	checkIfPlayerLeftHouse();
	checkArmWrestlingAction(); // <-- function with whole RPS mini game
}

void HouseState::render(sf::RenderTarget * target)
{
	// the order matters
	this->map.render(this->window);
	this->score.render(this->window);
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->skeleton.render(this->window);
	this->player.render(this->window);
}
