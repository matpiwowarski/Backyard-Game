#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
	double movementSpeed;
	bool isBlocked = false;
public:
	Player();
	~Player();

	// getters/setters
	bool getIsBlocked() const;

	//methods
	void move(const double &dt, const double xDirection, const double yDirection);
	void update(const double& dt);
	void block();
	void unblock();
};

