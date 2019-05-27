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
	std::vector<Dice> playerDices;
	std::vector<Dice> oponnentDices;
public:
	Dices();
	~Dices();

	//setters/getters
	sf::Text getNPCResultText();
	sf::Sprite getOponnentBoardSprite() const;

	Dice getPlayerDice(int diceNumber);

	Dice getOponnentDice(int diceNumber);
	//methods
	void fillDicesVector();
	void drawNPCChoice();
	sf::Sprite rightPressed(); // return cursor sprite
	sf::Sprite leftPressed(); // return cursor sprite

};

