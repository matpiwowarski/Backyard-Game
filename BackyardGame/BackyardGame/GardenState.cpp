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
	fence_down1.setSpritePosition(50, 305);
	fence_down2.setSpritePosition(440, 305);
	flowers1.setSpritePosition(120, 130);
	flowers1.getSprite().setScale(4.f, 4.f);
	flowers2.setSpritePosition(465, 130);
	flowers2.getSprite().setScale(4.f, 4.f);
	chest.setSpritePosition(380, 75);
	chest.getSprite().setScale(3.f, 3.f);
	rock.setSpritePosition(600, 450);
	rock.getSprite().setScale(6.f, 6.f);
	dice_guy.setSpritePosition(380, 300);
	player.setSpritePosition(10, 400);

	fence_left.getSprite().setTexture(textures[9]);
	fence_right.getSprite().setTexture(textures[10]);
	fence_up.getSprite().setTexture(textures[7]);
	fence_down1.getSprite().setTexture(textures[8]);
	fence_down2.getSprite().setTexture(textures[8]);
	flowers1.getSprite().setTexture(textures[11]);
	flowers2.getSprite().setTexture(textures[11]);
	chest.getSprite().setTexture(textures[12]);
	rock.getSprite().setTexture(textures[13]);
	dice_guy.getSprite().setTexture(textures[14]);
	player.getSprite().setTexture(textures[1]);

	this->dice_guy.setPlayersDicesSprites();
	this->dice_guy.setOponnentsDicesSprites();
}

GardenState::~GardenState()
{
}

void GardenState::checkMovementLimits(const double & dt)
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

void GardenState::colisionPreventEverything(const double & dt)
{
	colisionPreventing(player, fence_left, dt);
	colisionPreventing(player, fence_up, dt);
	colisionPreventing(player, fence_right, dt);
	colisionPreventing(player, fence_down1, dt);
	colisionPreventing(player, fence_down2, dt);
	colisionPreventing(player, score.getEntity(), dt);
	colisionPreventing(player, chest, dt);
	colisionPreventing(player, rock, dt);
	colisionPreventing(player, dice_guy, dt);
}

void GardenState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	checkMovementLimits(dt); // works ///NEW
	this->map.update(dt); // ?
	this->player.update(dt); // works
	this->score.update(dt); 
	this->fence_left.update(dt);
	this->fence_up.update(dt);
	this->fence_right.update(dt);
	this->fence_down1.update(dt);
	this->fence_down2.update(dt);
	this->flowers1.update(dt);
	this->flowers2.update(dt);
	this->chest.update(dt);
	this->rock.update(dt);
	this->dice_guy.update(dt);
	rotatingPlayer(player, dt);
	checkDicesAction();
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
	this->flowers1.render(this->window);
	this->flowers2.render(this->window);
	this->chest.render(this->window);
	this->rock.render(this->window);
	this->score.render(this->window);
	this->dice_guy.render(this->window);
	drawDicesSprites();  //it is needed for boards, buttons etc.
	drawPlayersDicesSprites();
	drawOponnentsDicesSprites();
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->window->draw(buttonText);
	this->window->draw(rerollsText);
	this->player.render(this->window);
}




//Dices functions

void GardenState::moveCursor()
{
	if (this->player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				// to ignore long time press
			}
			GameDicesToDraw[1] = dice_guy.rightPressed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				// to ignore long time press
			}
			GameDicesToDraw[1] = dice_guy.leftPressed();
		}
	}
}

void GardenState::activateDiceGuy()
{	
	this->GameDicesToDraw.push_back(this->dice_guy.getBoardSprite()); // board to draw						0
	this->GameDicesToDraw.push_back(this->dice_guy.getCursorSprite()); // cursor to draw					1
	this->GameDicesToDraw.push_back(this->dice_guy.getOponnentBoardSprite()); // oponnent board to draw		2
	this->GameDicesToDraw.push_back(this->dice_guy.getDiceButtonSprite()); // button to draw				3
}


void GardenState::fillDicesToDraw()
{
	for (int i = 0;i < 5;i++) {
		this->oponnentsDicesToDraw.push_back(dice_guy.getOponnentDice(i).getDiceSprite()); // NPC choice to draw
	}
	
	for (int i = 0;i < 5;i++) {
		this->playersDicesToDraw.push_back(dice_guy.getPlayerDice(i).getDiceSprite()); // NPC choice to draw
	}
}

void GardenState::drawDiceGuyChoice()
{
	activateDiceGuy();
	this->dice_guy.drawNPCChoice(); // draw NPC's choice	
}

void GardenState::drawDicesSprites()
{
	std::vector<sf::Sprite>::iterator it = GameDicesToDraw.begin();
	for (it; it != GameDicesToDraw.end(); it++)
	{
		this->window->draw(*it);
	}
}

void GardenState::drawPlayersDicesSprites()
{
	std::vector<sf::Sprite>::iterator it = playersDicesToDraw.begin();
	for (it; it != playersDicesToDraw.end(); it++)
	{
		this->window->draw(*it);
	}
}

void GardenState::drawOponnentsDicesSprites()
{
	std::vector<sf::Sprite>::iterator it = oponnentsDicesToDraw.begin();
	for (it; it != oponnentsDicesToDraw.end(); it++)
	{
		this->window->draw(*it);
	}
}

void GardenState::playDices()
{
	int number = 2;//to change later

	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	music.PlayBattleSoundtrack();
	blockPlayer();

	dice_guy.setDicesTexts(number);	//will change later
	fillDicesToDraw();				//might change later
	this->dice_guy.setOponnentsDicesSprites();
	this->dice_guy.setPlayersDicesSprites();

	this->buttonText = dice_guy.getButtonText();
	this->rerollsText = dice_guy.getRerollsText();
	if (score.getScore() >= 5)
	{
		blockPlayer();
		drawPlayersDicesSprites();
		drawOponnentsDicesSprites();
		drawDiceGuyChoice();
	}
	else
	{
		dice_guy.notEnoughCoins();
		this->NPCMessage = dice_guy.getNPCMessage();
		finishedMiniGame = true;
		music.PlayOutsideSoundtrack();
	}
}

void GardenState::DicesResult()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	this->GameDicesToDraw.erase(GameDicesToDraw.begin() + 1); // delete cursor
	for (int i = 0;i < 5;i++) {
		this->GameDicesToDraw.push_back(dice_guy.getOponnentDice(i).getDiceSprite()); // NPC choice to draw
	}
	this->NPCMessage = dice_guy.getNPCMessage(); // NPC message to draw
	this->NPCResultText = dice_guy.getNPCResultText(); // result to draw
	if (this->NPCResultText.getString() == "YOU WON")
		score.add(10);
	else if (this->NPCResultText.getString() == "YOU LOST")
		score.subtract(10);
	finishedMiniGame = true;
}


void GardenState::finishDices()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	this->GameDicesToDraw.clear();
	this->oponnentsDicesToDraw.clear();
	this->playersDicesToDraw.clear();
	this->NPCMessage.setString("");
	this->NPCResultText.setString("");
	this->buttonText.setString("");
	this->rerollsText.setString("");
	finishedMiniGame = false;
	unblockPlayer();
	music.PlayOutsideSoundtrack();
}

void GardenState::checkDicesAction()
{
	if (player.getIsBlocked() && finishedMiniGame)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			finishDices();
		}
	}
	if (player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			DicesResult();
		}
	}
	if (player.getIsBlocked() && !finishedMiniGame)
		moveCursor();
	if (player.getSprite().getGlobalBounds().intersects(dice_guy.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			playDices();
		}
	}
}

