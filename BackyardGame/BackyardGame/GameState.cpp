#include "GameState.h"

void GameState::drawRPSSprites()
{
	std::vector<sf::Sprite>::iterator it = GameRPSToDraw.begin();
	for (it; it != GameRPSToDraw.end(); it++)
	{
		this->window->draw(*it);
	}
	
}

void GameState::blockPlayer()
{
	player.block();
}

void GameState::unblockPlayer()
{
	player.unblock();
}

void GameState::moveCursor()
{
	if (player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				// to ignore long time press
			}
			GameRPSToDraw[1] = old_man.rightPressed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				// to ignore long time press
			}
			GameRPSToDraw[1] = old_man.leftPressed();
		}

	}
}

void GameState::activateOldMan()
{
	this->GameRPSToDraw.push_back(this->old_man.getBoardSprite()); // board to draw
	this->GameRPSToDraw.push_back(this->old_man.getCursorSprite()); // cursor to draw	
}

void GameState::playWithOldMan()
{
	activateOldMan();	
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { } // to ignore long time press
		this->old_man.playRockPaperScissors(); // draw NPC's choice
		this->GameRPSToDraw.push_back(old_man.getNPCChoiceSprite()); // NPC choice to draw
		this->NPCMessage = old_man.getNPCMessage(); // NPC message to draw
	}
 	score.add(10);
}

GameState::GameState(sf::RenderWindow* window): State(window)
{
	house.setPositionAndSize(350, 115, 140, 176);
	lake.setPositionAndSize(80, 450, 110, 78);
	lake.getSprite().setScale(6.f, 3.5f);
	old_man.setPositionAndSize(655, 525, 32, 46);
	red_tree.setPositionAndSize(620, 100, 106, 148);

	house.getSprite().setTexture(textures[0]);
	player.getSprite().setTexture(textures[1]);
	lake.getSprite().setTexture(textures[3]);
	old_man.getSprite().setTexture(textures[4]);
	red_tree.getSprite().setTexture(textures[5]);
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
	if (!player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player.getSprite().setTexture(textures[2]);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player.getSprite().setTexture(textures[1]);
	}			
}

void GameState::checkDoor(Player & player, const double& dt)
{
	if(player.getSprite().getGlobalBounds().intersects(this->house.getSprite().getGlobalBounds()))
	{
		if(player.getPosition().x > 380 && player.getPosition().x < 430)
			if(player.getPosition().y > 200)
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					house.getSprite().setTexture(textures[6]);
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
	this->old_man.update(dt);
	this->red_tree.update(dt);
	this->score.update(dt);
	rotatingPlayer(player,dt);
	checkDoor(player, dt);
	if (player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
			unblockPlayer();
			this->GameRPSToDraw.clear();
			this->NPCMessage.setString("");
		}
	}

	moveCursor();
	if (player.getSprite().getGlobalBounds().intersects(old_man.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			blockPlayer();
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { } // to ignore long time press
			playWithOldMan();
			return;
		}	
	}

	colisionPreventing(player, house, dt);
	colisionPreventing(player, lake, dt);
	colisionPreventing(player, old_man, dt);
	colisionPreventing(player, red_tree, dt);
	colisionPreventing(player, score.getEntity(), dt);
}

void GameState::render(sf::RenderTarget* target)
{
	// the order matters
	this->map.render(this->window);
	this->house.render(this->window);
	this->lake.render(this->window);
	this->player.render(this->window);
	this->old_man.render(this->window);
	this->red_tree.render(this->window);
	this->score.render(this->window);
	drawRPSSprites();
	this->window->draw(NPCMessage);
}
