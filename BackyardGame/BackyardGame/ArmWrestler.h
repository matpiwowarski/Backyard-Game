#pragma once
#include "NPC.h"

// Singleton pattern

class ArmWrestler : public NPC
{
private:
	ArmWrestler();
public:
	void updateCursorSpritePosition();
	static ArmWrestler & getInstance();
	void loadBoardTexture();
	// setters / getters
	void setCursorIndex(int index);
	int getCursorIndex() const;
};

