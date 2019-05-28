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

void HouseState::initializeBoardInfo()
{
	if (!BoardInfoFont.loadFromFile("../Assets/fonts/CarterOne.ttf")) // PressStart2P-Regular.ttf
	{
		throw; // error;
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
	flags[0].getSprite().setTexture(textures[18]);
	flags[1].getSprite().setTexture(textures[18]);
	flags[2].getSprite().setTexture(textures[18]);
}

void HouseState::initializeNPCs()
{
	skeleton.setSpritePosition(250, 150);
	skeleton.getSprite().setTexture(textures[15]);
	skeleton.getSprite().setScale(sf::Vector2f(4.f, 4.f));

	vampire.setSpritePosition(250, 300);
	vampire.getSprite().setTexture(textures[16]);
	vampire.getSprite().setScale(sf::Vector2f(3.f, 3.f));

	priest.setSpritePosition(250, 450);
	priest.getSprite().setTexture(textures[17]);
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
	if (player.getIsBlocked())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			miniGameResults();
		}
	}
	if (player.getSprite().getGlobalBounds().intersects(skeleton.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			bet = skeleton.getBet();
			playArmWrestling(skeleton);
		}
	}
	else
	if (player.getSprite().getGlobalBounds().intersects(vampire.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			bet = vampire.getBet();
			playArmWrestling(vampire);
		}
	}
	else
	if (player.getSprite().getGlobalBounds().intersects(priest.getSprite().getGlobalBounds()))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			bet = priest.getBet();
			playArmWrestling(priest);
		}
	}
}

void HouseState::playArmWrestling(ArmWrestler armwrestler)
{
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	music.PlayBattleSoundtrack();
	blockPlayer();
	if (score.getScore() >= this->bet)
	{
		blockPlayer();
		DisplayBoardAndPlay(armwrestler);
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

void HouseState::DisplayBoardAndPlay(ArmWrestler armwrestler)
{
	this->miniGameSpritesToDraw.push_back(armwrestler.getBoardSprite());	// board to draw		0
	this->miniGameSpritesToDraw.push_back(armwrestler.getCursorSprite());	// cursor to draw		1
	this->BoardInfo2.setString("YOUR OPPONENT");
	this->BoardInfo1.setString("YOU");
}

HouseState::HouseState()
{
}

HouseState::HouseState(sf::RenderWindow * window): GameState(window)
{
	map.LoadHouseMap(); // load map
	player.setSpritePosition(420, 530);
	player.getSprite().setTexture(textures[1]);

	initializeNPCs();
	initializeFlags();
	initializeBoardInfo();
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
	checkArmWrestlingAction(); // <-- function with whole RPS mini game
	colisionPreventEverything(dt); // <-- preventing collisions with all objects
	checkIfPlayerLeftHouse();
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
	this->score.render(this->window);
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
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {} // to ignore long time press
	//this->NPCMessage = dice_guy.getNPCMessage(); // NPC message to draw
	//this->NPCResultText = dice_guy.getNPCResultText(); // result to draw
	if (this->NPCResultText.getString() == "YOU WON")
		score.add(bet);
	else if (this->NPCResultText.getString() == "YOU LOST")
		score.subtract(bet);
	finishedMiniGame = true;
}
