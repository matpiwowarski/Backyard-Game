#include "GameState.h"

GameState::GameState(sf::RenderWindow* window): State(window)
{
	house.setPositionAndSize(350, 115, 140, 176);
	lake.setPositionAndSize(80, 450, 110, 78);
	lake.getSprite().setScale(6.f, 3.5f);

	house.getSprite().setTexture(textures[0]);
	player.getSprite().setTexture(textures[1]);
	lake.getSprite().setTexture(textures[3]);
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "THE END" << std::endl;
}

void GameState::colisionPreventing(Player & player, Entity & object, const double &dt)
{
	if (player.getSprite().getGlobalBounds().intersects(object.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.move(dt, 1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.move(dt, -1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.move(dt, 0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.move(dt, 0.f, -1.f);
		}
	}
}

void GameState::rotatingPlayer(Player & player, const double& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.getSprite().setTexture(textures[2]);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.getSprite().setTexture(textures[1]);
			
}

void GameState::checkDoor(Player & player, const double& dt)
{
	if(player.getSprite().getGlobalBounds().intersects(this->house.getSprite().getGlobalBounds()))
	{
		if(player.getPosition().x > 400 && player.getPosition().x < 430)
			if(player.getPosition().y > 200)
				house.getSprite().setTexture(textures[4]);
	}
}

void GameState::updateKeybinds(const double & dt)
{
	this->checkQuit();
}

void GameState::update(const double& dt)
{
	this->updateKeybinds(dt);
	this->map.update(dt);
	this->house.update(dt);
	this->lake.update(dt);
	this->player.update(dt);
	this->score.update(dt);
	rotatingPlayer(player,dt);
	checkDoor(player, dt);
	colisionPreventing(player, house, dt);
	colisionPreventing(player, lake, dt);
}

void GameState::render(sf::RenderTarget* target)
{
	// the order matters
	this->map.render(this->window);
	this->house.render(this->window);
	this->lake.render(this->window);
	this->player.render(this->window);
	this->score.render(this->window);
}
