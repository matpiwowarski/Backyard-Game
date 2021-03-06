#pragma once
#include "NPC.h"
#include "Dice.h"
class Dices :
	public NPC
{
protected:
	void randomChoice();
	void uploadNPCChoiceTexture();
	void uploadPlayersChoiceTexture();
	void loadBoardTexture();
	sf::Texture oponnentBoardTexture;
	sf::Sprite oponnentBoardSprite;
	void loadOponnentBoardTexture();
	void updateCursorSpritePosition();
	sf::Texture diceButtonTexture;
	sf::Sprite diceButtonSprite;
	void loadDiceButtonTexture();
	int playerScore, oponnentScore;
	std::vector<Dice> playerDices;
	std::vector<Dice> oponnentDices;
	sf::Text rerollsText;
	sf::Text buttonText;
	int rerollsNumber=2;
public:
	Dices();
	~Dices();

	//setters/getters
	void setDicesTexts(int reroll);
	void setOponnentsDicesSprites();
	void setPlayersDicesSprites();
	void setRerollsNumber(int number);

	sf::Text getNPCResultText();
	sf::Text getButtonText() const;
	sf::Text getRerollsText() const;

	sf::Sprite getOponnentBoardSprite() const;
	sf::Sprite getDiceButtonSprite() const;
	
	int getCursorIndex();
	int getRerollsNumber();

	Dice & getPlayerDice(int diceNumber);
	Dice & getOponnentDice(int diceNumber);
	
	//methods
	void fillDicesVector();		//makes 'Dice' class objects and putting them in playerDices vector and oponnentDices vector
	void drawNPCChoice();		//setting NPC's string
	void redrawDices();      //redraws dices that player choosed to do so
	void redrawOponnentsDicesFirstTime();  
	void redrawOponnentsDicesSecondTime();  //NPC's tactic changes between round of dices(second time is re-rollng more agressive if loosing, and more passive if winning)
	void helpForRedrawing(int i); //i is a number taken from "for" loop
	void countScore();		
	void changeTexture();  //change dice texture if is chosen to be redrawn


	sf::Sprite rightPressed(); // return cursor sprite
	sf::Sprite leftPressed(); // return cursor sprite

};

