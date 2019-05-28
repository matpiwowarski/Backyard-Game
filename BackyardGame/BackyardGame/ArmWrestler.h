#pragma once
#include "NPC.h"
class ArmWrestler : public NPC
{
private:
	int level;
	int bet;
public:
	void loadBoardTexture();
	ArmWrestler(int level);
	~ArmWrestler();
	// setters / getters
	int getLevel() const;
	int getBet() const;
};

