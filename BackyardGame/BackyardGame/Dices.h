#pragma once
#include "NPC.h"
#include "Dice.h"
class Dices :
	public NPC
{
protected:
	void randomChoice();
	void uploadNPCChoiceTexture();
	void loadBoardTexture();
	void loadOponnentBoardTexture();
	void updateCursorSpritePosition();
	int playerScore, oponnentScore;
	Dice playerDice1, playerDice2, playerDice3, playerDice4, playerDice5, oponnentDice1, oponnentDice2, oponnentDice3, oponnentDice4, oponnentDice5;
public:
	Dices();
	~Dices();

	//setters/getters
	sf::Text getNPCResultText();
	sf::Sprite getOponnentBoardSprite() const;

	Dice getPlayerDice1();
	Dice getPlayerDice2();
	Dice getPlayerDice3();
	Dice getPlayerDice4();
	Dice getPlayerDice5();

	Dice getOponnentDice1();
	Dice getOponnentDice2();
	Dice getOponnentDice3();
	Dice getOponnentDice4();
	Dice getOponnentDice5();
	//methods
	void drawNPCChoice();
	sf::Sprite rightPressed(); // return cursor sprite
	sf::Sprite leftPressed(); // return cursor sprite

};

