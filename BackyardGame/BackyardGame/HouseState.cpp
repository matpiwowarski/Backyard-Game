#include "HouseState.h"
#define ClickingNPCTime 7000

bool HouseState::hiddenLadder = true;

HouseState::HouseState()
{
}

HouseState::HouseState(sf::RenderWindow * window) : GameState(window)
{
	this->music.PlayScarySoundtrack();
	this->NPCClock.restart();
	this->map.LoadHouseMap(); // load map
	this->player.setSpritePosition(420, 530);
	setTexture(player, 1);
	this->ladder.setSpritePosition(500, 100);
	setTexture(ladder, 19);

	initializeNPCs();
	initializeFlags();
	initializeBoardInfo();
}

HouseState::~HouseState()
{
}

template<typename Type> void HouseState::setTexture(Type & t, int i)
{
	t.getSprite().setTexture(this->textures[i]);
}

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

void HouseState::initializeBoardInfo()
{

	try
	{
		if (!BoardInfoFont.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
			throw - 1;
	}
	catch (int)
	{
		std::cout << "Problem with font loading";
	}

	this->BoardInfo1.setFont(BoardInfoFont);
	this->BoardInfo1.setFillColor(sf::Color::White);
	sf::Vector2f position1(180.f, 365.f);
	this->BoardInfo1.setPosition(position1);
	this->BoardInfo1.setScale(sf::Vector2f(0.7, 0.7));

	this->BoardInfo2.setFont(BoardInfoFont);
	this->BoardInfo2.setFillColor(sf::Color::White);
	sf::Vector2f position2(515.f, 365.f);
	this->BoardInfo2.setPosition(position2);
	this->BoardInfo2.setScale(sf::Vector2f(0.6, 0.6));

	this->NPCResultText.setFont(BoardInfoFont);
	this->NPCResultText.setFillColor(sf::Color::White);
	sf::Vector2f position3(330.f, 420.f);
	this->NPCResultText.setPosition(position3);
	this->NPCResultText.setScale(sf::Vector2f(1, 1));
}

void HouseState::initializeFlags()
{
	Entity flag;
	flags.push_back(flag);
	flags.push_back(flag);
	flags.push_back(flag);
	flags[0].setSpritePosition(200, 150);
	flags[1].setSpritePosition(200, 300);
	flags[2].setSpritePosition(200, 450);
	setTexture(flags[0], 18);
	setTexture(flags[1], 18);
	setTexture(flags[2], 18);
}

void HouseState::initializeNPCs()
{
	skeleton.setSpritePosition(250, 150);
	setTexture(skeleton, 15);
	skeleton.getSprite().setScale(sf::Vector2f(4.f, 4.f));

	vampire.setSpritePosition(250, 300);
	setTexture(vampire, 16);
	vampire.getSprite().setScale(sf::Vector2f(3.f, 3.f));

	priest.setSpritePosition(250, 450);
	setTexture(priest, 17);
	priest.getSprite().setScale(sf::Vector2f(2.5, 2.5));
}

void HouseState::checkArmWrestlingAction()
{
	if (player.getIsBlocked() && finishedMiniGame)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			finishArmWrestling();
		}
	}
	if (player.getIsBlocked() && !finishedMiniGame)
	{
	
		if (this->cursorIndex == 0 || cursorIndex == 19) 	// end game
		{
			miniGameResults();
		}
		else
		{
			if (NPCClock.getElapsedTime().asMilliseconds() >=  ClickingNPCTime / this->bet) 
			{
				cursorIndex--;
				NPCClock.restart();
			}
			fastClicking();
			this->priest.setCursorIndex(this->cursorIndex);
			this->priest.updateCursorSpritePosition();
			this->miniGameSpritesToDraw[1] = priest.getCursorSprite();
		}
	}
	if (!player.getIsBlocked())
	{
		if (player.getSprite().getGlobalBounds().intersects(skeleton.getSprite().getGlobalBounds()))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				bet = 30; 
				playArmWrestling(skeleton);
			}
		}
		else
		if (player.getSprite().getGlobalBounds().intersects(vampire.getSprite().getGlobalBounds()))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				bet = 20; 
				playArmWrestling(vampire);
			}
		}
		else
		if (player.getSprite().getGlobalBounds().intersects(priest.getSprite().getGlobalBounds()))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				bet = 10; 
				playArmWrestling(priest);
			}
		}
	}
}


void HouseState::fastClicking()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
  		cursorIndex++;
	}
}

void HouseState::checkIsLadderUsed()
{
	if (player.getSprite().getGlobalBounds().intersects(ladder.getSprite().getGlobalBounds()) && !hiddenLadder)
	{
		usedLadder = true;
	}
}

void HouseState::checkEndGame()
{
	if (usedLadder)
	{
		blockPlayer();
		this->NPCMessage = skeleton.getEndGameMessage();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			quit = true;
		}
	}

}

void HouseState::playArmWrestling(ArmWrestler armwrestler)
{
	this->cursorIndex = 9;
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	music.PlayBattleSoundtrack();
	blockPlayer();
	if (score.getScore() >= this->bet)
	{
		blockPlayer();
		DisplayBoard(armwrestler);
	}
	else
	{
		armwrestler.notEnoughCoins();
		this->NPCMessage = armwrestler.getNPCMessage();
		finishedMiniGame = true;
		music.PlayScarySoundtrack();
	}

}

void HouseState::finishArmWrestling()
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	this->miniGameSpritesToDraw.clear();
	this->NPCMessage.setString("");
	this->NPCResultText.setString("");
	this->BoardInfo1.setString("");
	this->BoardInfo2.setString("");
	finishedMiniGame = false;
	unblockPlayer();
	music.PlayScarySoundtrack();
}

void HouseState::DisplayBoard(ArmWrestler armwrestler)
{
	this->miniGameSpritesToDraw.push_back(armwrestler.getBoardSprite());	// board to draw		0
	this->miniGameSpritesToDraw.push_back(armwrestler.getCursorSprite());	// cursor to draw		1
	this->BoardInfo2.setString("YOUR OPPONENT");
	this->BoardInfo1.setString("YOU");
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

template<typename a, typename b> void HouseState::colisionPreventing(a& t1, b& t2, const double & dt)
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

void HouseState::colisionPreventEverything(const double & dt)
{
	colisionPreventing(player, skeleton, dt);
	colisionPreventing(player, vampire, dt);
	colisionPreventing(player, priest, dt);
	colisionPreventing(player, flags[0], dt);
	colisionPreventing(player, flags[1], dt);
	colisionPreventing(player, flags[2], dt);
}

void HouseState::update(const double & dt)
{
	this->updateKeybinds(dt); // works
	this->checkMovementLimits(dt); // works
	this->map.update(dt); // ?
	this->player.update(dt); // works
	this->score.update(dt); // works
	this->skeleton.update(dt); // ?
	this->vampire.update(dt); // ?
	this->priest.update(dt); // ?
	rotatingPlayer(player, dt);

	if (!usedLadder)
	{
		checkArmWrestlingAction(); // <-- function with whole RPS mini game
		checkIfPlayerLeftHouse();
		checkIsLadderUsed();
	}

	this->checkEndGame(); // ending the game after using the ladder
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
}

void HouseState::render(sf::RenderTarget * target)
{

	// the order matters
	this->map.render(this->window);
	this->flags[0].render(this->window);
	this->flags[1].render(this->window);
	this->flags[2].render(this->window);
	this->skeleton.render(this->window);
	this->vampire.render(this->window);
	this->priest.render(this->window);
	this->player.render(this->window);
	drawMiniGameSprites();
	this->window->draw(NPCMessage);
	this->window->draw(NPCResultText);
	this->window->draw(BoardInfo1);
	this->window->draw(BoardInfo2);
	this->window->draw(NPCResultText);
	this->score.render(this->window);

	if (!hiddenLadder)
		this->ladder.render(this->window);

}

void HouseState::drawMiniGameSprites()
{
	std::vector<sf::Sprite>::iterator it = miniGameSpritesToDraw.begin();
	for (it; it != miniGameSpritesToDraw.end(); it++)
	{
		this->window->draw(*it);
	}
}

void HouseState::miniGameResults()
{
	this->miniGameSpritesToDraw.erase(miniGameSpritesToDraw.begin() + 1); // delete cursor

	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press

	try
	{
		if (cursorIndex == 0)
		{
			this->NPCResultText.setString("YOU LOST");
			score.subtract(bet);
		}
		else if (cursorIndex == 19)
		{
			this->NPCResultText.setString("YOU WON");
			score.add(bet);
			if (bet == 30)
			{
				this->hiddenLadder = false;
			}
		}
		else
		{

			throw -1;
		}
	}
	catch (int)
	{
		std::cout << "Cursor index is out of range";
	}


	finishedMiniGame = true;
}




