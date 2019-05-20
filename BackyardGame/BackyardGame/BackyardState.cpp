#include "BackyardState.h"

BackyardState::BackyardState()
{

}

BackyardState::BackyardState(sf::RenderWindow * window) : GameState(window)
{
	map.LoadBackyardMap(); // load map

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


BackyardState::~BackyardState()
{
}

void BackyardState::checkDoor(Player & player, const double & dt)
{
	if (player.getPosition().x > 380 && player.getPosition().x < 430)
		if (player.getPosition().y > 200 && player.getPosition().y < 300)
		{
			if (areDoorOpen == true)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					enteredHouse = true;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				if (areDoorOpen == false)
				{
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}
					house.getSprite().setTexture(textures[6]);
					areDoorOpen = true;
				}
				else
				{
					while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}
					house.getSprite().setTexture(textures[0]);
					areDoorOpen = false;
				}
		}
}

void BackyardState::colisionPreventEverything(const double & dt)
{
	colisionPreventing(player, house, dt);
	colisionPreventing(player, lake, dt);
	colisionPreventing(player, old_man, dt);
	colisionPreventing(player, red_tree, dt);
	colisionPreventing(player, score.getEntity(), dt);
}

void BackyardState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	this->map.update(dt); // ?
	this->house.update(dt); // ?
	this->lake.update(dt); // ?
	this->player.update(dt); // works
	this->old_man.update(dt); // ?
	this->red_tree.update(dt); // ?
	this->score.update(dt); // works
	// other
	rotatingPlayer(player, dt);
	checkDoor(player, dt);
	checkRPSAction(); // <-- function with whole RPS mini game
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
}

void BackyardState::render(sf::RenderTarget * target)
{
	// the order matters
	this->map.render(this->window);
	this->house.render(this->window);
	this->lake.render(this->window);
	this->old_man.render(this->window);
	this->red_tree.render(this->window);
	this->score.render(this->window);
	drawRPSSprites();
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->player.render(this->window);
}

void BackyardState::moveCursor()
{
	if (this->player.getIsBlocked())
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

void BackyardState::activateOldMan()
{
	this->GameRPSToDraw.push_back(this->old_man.getBoardSprite()); // board to draw
	this->GameRPSToDraw.push_back(this->old_man.getCursorSprite()); // cursor to draw	
}

void BackyardState::drawOldManChoice()
{
	activateOldMan();
	this->old_man.drawNPCChoice(); // draw NPC's choice	
}

void BackyardState::drawRPSSprites()
{
	std::vector<sf::Sprite>::iterator it = GameRPSToDraw.begin();
	for (it; it != GameRPSToDraw.end(); it++)
	{
		this->window->draw(*it);
	}
}

void BackyardState::playRPS()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	blockPlayer();
	if (score.getScore() >= 5)
	{
		blockPlayer();
		drawOldManChoice();
	}
	else
	{
		old_man.notEnoughCoins();
		this->NPCMessage = old_man.getNPCMessage();
		finishedMiniGame = true;
	}
}

void BackyardState::RPSResult()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	this->GameRPSToDraw.erase(GameRPSToDraw.begin() + 1); // delete cursor
	this->GameRPSToDraw.push_back(old_man.getNPCChoiceSprite()); // NPC choice to draw
	this->NPCMessage = old_man.getNPCMessage(); // NPC message to draw
	this->NPCResultText = old_man.getNPCResultText(); // result to draw
	if (this->NPCResultText.getString() == "YOU WON")
		score.add(5);
	else if (this->NPCResultText.getString() == "YOU LOST")
		score.subtract(5);
	finishedMiniGame = true;
}

void BackyardState::finishRPS()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	this->GameRPSToDraw.clear();
	this->NPCMessage.setString("");
	this->NPCResultText.setString("");
	finishedMiniGame = false;
	unblockPlayer();
}

void BackyardState::checkRPSAction()
{
	if (player.getIsBlocked() && finishedMiniGame)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			finishRPS();
		}
	}
	if (player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			RPSResult();
		}
	}
	if (player.getIsBlocked() && !finishedMiniGame)
		moveCursor();
	if (player.getSprite().getGlobalBounds().intersects(old_man.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			playRPS();
		}
	}
}
