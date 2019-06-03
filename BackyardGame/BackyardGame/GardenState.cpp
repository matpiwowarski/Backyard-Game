#include "GardenState.h"

bool GardenState::wasDiceGuyMoved = false;

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
	if (wasDiceGuyMoved == false) {
		dice_guy.setSpritePosition(380, 300);
	}
	else dice_guy.setSpritePosition(328, 300);

	player.setSpritePosition(10, 360);

	setTexture(fence_left, 9);
	setTexture(fence_right, 10);
	setTexture(fence_up, 7);
	setTexture(fence_down1, 8);
	setTexture(fence_down2, 8);
	setTexture(flowers1, 11);
	setTexture(flowers2, 11);
	setTexture(chest, 12);
	setTexture(rock, 13);
	setTexture(dice_guy, 14);
	setTexture(player, 1);


	this->dice_guy.setPlayersDicesSprites();
	this->dice_guy.setOponnentsDicesSprites();
}

GardenState::~GardenState()
{
}

template<typename Type> void GardenState::setTexture(Type & t, int i)
{
	t.getSprite().setTexture(this->textures[i]);
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

template<typename a, typename b> void GardenState::colisionPreventing(a& t1, b& t2, const double& dt)
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
	this->player.update(dt); // works
	this->score.update(dt);
	//this->dice_guy.update(dt);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)|| sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				// to ignore long time press
			}
			GameDicesToDraw[1] = dice_guy.rightPressed();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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
		this->oponnentsDicesToDraw.push_back(dice_guy.getOponnentDice(i).getDiceSprite()); 
	}

	for (int i = 0;i < 5;i++) {
		this->playersDicesToDraw.push_back(dice_guy.getPlayerDice(i).getDiceSprite()); 
	}
}

void GardenState::drawDiceGuyChoice()
{
	this->dice_guy.drawNPCChoice(); // draw NPC's message	
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
	
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press

	blockPlayer();

	dice_guy.setDicesTexts(this->dice_guy.getRerollsNumber());	//2

	this->dice_guy.setOponnentsDicesSprites();
	this->dice_guy.setPlayersDicesSprites();

	this->buttonText = dice_guy.getButtonText();
	this->rerollsText = dice_guy.getRerollsText();
	this->window->draw(rerollsText);

	activateDiceGuy();

	music.PlayBattleSoundtrack();
	blockPlayer();
	drawPlayersDicesSprites();
	drawOponnentsDicesSprites();
	drawDiceGuyChoice();

}

void GardenState::DicesResult()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	this->GameDicesToDraw.erase(GameDicesToDraw.begin() + 1); // delete cursor
	for (int i = 0;i < 5;i++) {
		this->GameDicesToDraw.push_back(dice_guy.getOponnentDice(i).getDiceSprite()); // NPC choice to draw
	}
	this->dice_guy.countScore();
	this->NPCMessage = dice_guy.getNPCMessage(); // NPC message to draw
	this->NPCResultText = dice_guy.getNPCResultText(); // result to draw
	if (this->NPCResultText.getString() == "YOU WON")
	{
		score.add(10);
	}
	else if (this->NPCResultText.getString() == "YOU LOST")
		if (score.getScore() > 0) {
			score.subtract(10);
		}
	finishedMiniGame = true;
}


void GardenState::finishDices()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	this->GameDicesToDraw.clear();
	this->oponnentsDicesToDraw.clear();
	this->playersDicesToDraw.clear();
	this->NPCMessage.setString("");
	this->buttonText.setString("");
	this->rerollsText.setString("");
	this->dice_guy.setRerollsNumber(2);
	finishedMiniGame = false;
	if (this->NPCResultText.getString() == "YOU WON")
	{
		wasDiceGuyMoved = true;
		this->dice_guy.setSpritePosition(328, 300);
	}
	this->NPCResultText.setString("");
	unblockPlayer();
	music.PlayOutsideSoundtrack();
}

void GardenState::checkDicesAction()
{
	DiceAction0Rerolls();

	if (player.getIsBlocked() && !finishedMiniGame)
		moveCursor();
	if (player.getSprite().getGlobalBounds().intersects(dice_guy.getSprite().getGlobalBounds()))
	{
		if (this->dice_guy.getRerollsNumber() == 1 &&
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
		{
			DicesAction1Rerolls();
		}
		if (this->dice_guy.getRerollsNumber() == 2)
		{
			DicesAction2Rerolls();
		}
	}
}


void GardenState::DiceAction0Rerolls()
{
	if (player.getIsBlocked() && finishedMiniGame)
	{
		if (dice_guy.getCursorIndex() == 5 && this->dice_guy.getRerollsNumber() == 0 &&
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
		{
			this->dice_guy.setRerollsNumber(2);
			wereBoardsDrawn = false;
			finishDices();
		}
		else if (dice_guy.getCursorIndex() != 5 &&
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) {
			//text you can't reroll
		}
	}
	if (player.getIsBlocked())
	{
		if (dice_guy.getCursorIndex() == 5 && this->dice_guy.getRerollsNumber() == 0 &&
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
		{
			DicesResult();
		}
	}
}



void GardenState::DicesAction1Rerolls()
{
	if (this->dice_guy.getCursorIndex() < 5 &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))  //for not leaving vector range
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}
		if (this->dice_guy.getPlayerDice(this->dice_guy.getCursorIndex()).getIsChosenToReroll() == false()) {
			this->dice_guy.getPlayerDice(this->dice_guy.getCursorIndex()).setIsChosenToReroll(true);
		}
		else this->dice_guy.getPlayerDice(this->dice_guy.getCursorIndex()).setIsChosenToReroll(false);
		this->dice_guy.changeTexture();   //lighting up dices that are choosen to re-roll
	}

	if (this->dice_guy.getCursorIndex() == 5 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
	{
	
		this->dice_guy.redrawOponnentsDicesSecondTime();
		this->dice_guy.setRerollsNumber(0);
		DicesPack();
		this->buttonText.setString("    End!");
	}
}


void GardenState::DicesAction2Rerolls()
{
	if (wereBoardsDrawn == false &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
	{
		fillDicesToDraw();
		playDices();
		wereBoardsDrawn = true;
	}

	if (this->dice_guy.getCursorIndex() < 5 &&
		(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))  //for not leaving vector range
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}
		if (this->dice_guy.getPlayerDice(this->dice_guy.getCursorIndex()).getIsChosenToReroll() == false()) {
			this->dice_guy.getPlayerDice(this->dice_guy.getCursorIndex()).setIsChosenToReroll(true);
		}
		else this->dice_guy.getPlayerDice(this->dice_guy.getCursorIndex()).setIsChosenToReroll(false);
		this->dice_guy.changeTexture();  //lighting up dices that are choosen to re-roll
	}


	if (this->dice_guy.getCursorIndex() == 5 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
	{
		this->dice_guy.redrawOponnentsDicesFirstTime();
		this->dice_guy.setRerollsNumber(1);
		DicesPack();
	}
}

void GardenState::DicesPack()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {}
	this->dice_guy.countScore();
	this->dice_guy.redrawDices();
	this->rerollsText.setString("");
	this->dice_guy.setDicesTexts(this->dice_guy.getRerollsNumber());
	rerollsText = dice_guy.getRerollsText();
}
