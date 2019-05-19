#include "NPC.h"

class RPS :
	public NPC
{
private:
	void randomChoice();
	void uploadNPCChoiceTexture();
	void loadBoardTexture();
	void updateCursorSpritePosition();
public:
	RPS();
	~RPS();



	//getters / setters
	sf::Text getNPCResultText();

	//methods
	void drawNPCChoice();
	sf::Sprite rightPressed(); // return cursor sprite
    sf::Sprite leftPressed(); // return cursor sprite
};
