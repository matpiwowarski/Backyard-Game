#pragma once
#include "NPC.h"
class Dices :
	public NPC
{
protected:
	void randomChoice();
	void randomChoice2();
	void randomChoice3();
	void randomChoice4();
	void randomChoice5();
	void uploadNPCChoiceTexture();
	void loadBoardTexture();
	void loadOponnentBoardTexture();
	void updateCursorSpritePosition();
	int playerScore, oponnentScore;
public:
	Dices();
	~Dices();

	//setters/getters
	sf::Text getNPCResultText();
	sf::Sprite getOponnentBoardSprite() const;

	//methods
	void drawNPCChoice();
	void drawPlayerChoice();
	sf::Sprite rightPressed(); // return cursor sprite
	sf::Sprite leftPressed(); // return cursor sprite

};

