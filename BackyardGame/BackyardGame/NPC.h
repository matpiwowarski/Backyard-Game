#pragma once
#include "Entity.h"
#include <random>
#include <chrono>
#include <ctime>
#include <vector>

class NPC : public Entity
{
protected: 
	int choice, choice2, choice3, choice4, choice5;
	int cursorIndex = 0;
	sf::Texture boardTexture, oponnentBoardTexture;
	sf::Texture choiceTexture, choiceTexture2, choiceTexture3, choiceTexture4, choiceTexture5;
	sf::Texture cursorTexture;
	sf::Sprite boardSprite, oponnentBoardSprite;
	sf::Sprite choiceSprite, choiceSprite2, choiceSprite3, choiceSprite4, choiceSprite5;
	sf::Sprite cursorSprite;
	sf::Text message;
	sf::Text result;
	sf::Font messageFont;
	virtual void uploadNPCChoiceTexture()=0;
	void loadCursorTexture();
	virtual void randomChoice()=0;
	virtual void loadBoardTexture()=0;
	virtual void updateCursorSpritePosition()=0;
public:
	NPC();
	~NPC();
// getters / setters
	virtual sf::Sprite getBoardSprite() const;
	virtual sf::Sprite getNPCChoiceSprite() const;
	virtual sf::Sprite getNPCChoice2Sprite() const;
	virtual sf::Sprite getNPCChoice3Sprite() const;
	virtual sf::Sprite getNPCChoice4Sprite() const;
	virtual sf::Sprite getNPCChoice5Sprite() const;
	virtual sf::Sprite getCursorSprite() const;
	virtual sf::Text getNPCMessage() const;
	virtual sf::Text getNPCResultText();
	virtual sf::Font getMessageFont() const;

// methods
virtual void drawNPCChoice()=0;
virtual sf::Sprite rightPressed()=0; // return cursor sprite
virtual sf::Sprite leftPressed()=0; // return cursor sprite
void notEnoughCoins(); // change message
};

