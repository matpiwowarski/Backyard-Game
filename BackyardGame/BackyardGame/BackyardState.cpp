#include "BackyardState.h"

BackyardState::BackyardState()
{

}

BackyardState::BackyardState(sf::RenderWindow * window) : GameState(window)
{
	map.LoadBackyardMap(); // load map
	//entities settings
	player.setSpritePosition(50, 160);
	house.setSpritePosition(350, 115);
	lake.setSpritePosition(80, 450);
	lake.getSprite().setScale(6.f, 3.5f);
	old_man.setSpritePosition(655, 525);
	red_tree.setSpritePosition(620, 100);

	setTexture(house, 0);
	setTexture(player, 1);
	setTexture(lake, 3);
	setTexture(old_man, 4);
	setTexture(red_tree, 5);

	//setting music
	music.PlayOutsideSoundtrack();
}


BackyardState::~BackyardState()
{
}

template<typename Type> void BackyardState::setTexture(Type & t, int i)
{
	t.getSprite().setTexture(this->textures[i]);
}

void BackyardState::checkMovementLimits(const double& dt)
{
	if (this->player.getPosition().x <= 0)
		this->player.move(dt, 1.f, 0.f);
	if (this->player.getPosition().x >= 768)
		this->player.move(dt, -1.f, 0.f);
	if (this->player.getPosition().y <= 0)
		this->player.move(dt, 0.f, 1.f);
	if (this->player.getPosition().y >= 545)
		this->player.move(dt, 0.f, -1.f);
}

void BackyardState::checkDoor(Player & player, const double & dt)
{
	if (player.getPosition().x > 380 && player.getPosition().x < 430)
		if (player.getPosition().y > 170 && player.getPosition().y < 300)
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

void BackyardState::colisionPreventEverything(const double& dt)
{
	colisionPreventing(player, house, dt);
	colisionPreventing(player, lake, dt);
	colisionPreventing(player, old_man, dt);
	colisionPreventing(player, red_tree, dt);
	colisionPreventing(player, score.getEntity(), dt);
}

template<typename a, typename b> void BackyardState::colisionPreventing(a& t1, b& t2, const double& dt)
{
	if (t1.getSprite().getGlobalBounds().intersects(t2.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			t1.move(dt, 1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			t1.move(dt, -1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			t1.move(dt, 0.f, 1.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			t1.move(dt, 0.f, -1.f);
		}
	}
}

void BackyardState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	this->checkMovementLimits(dt); // works
	this->player.update(dt); // works
	this->score.update(dt); // works 
	// other
	rotatingPlayer(player, dt);
	checkDoor(player, dt);
	checkRPSAction(); // <-- function with whole RPS mini game
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
	checkIfPlayerEnteredGarden();
}

void BackyardState::render(sf::RenderTarget * target)
{
	// the order matters
	this->map.render(this->window);
	this->house.render(this->window);
	this->lake.render(this->window);
	this->old_man.render(this->window);
	this->red_tree.render(this->window);
	drawRPSSprites();
	this->player.render(this->window);
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->score.render(this->window);
}

void BackyardState::checkIfPlayerEnteredGarden()
{
	if (player.getPosition().x > 750) {
		enteredGarden = true;
	}
}

void BackyardState::moveCursor()
{
	if (this->player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				// to ignore long time press
			}
			GameRPSToDraw[1] = old_man.rightPressed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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
	music.PlayBattleSoundtrack();
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
	music.PlayOutsideSoundtrack();
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
