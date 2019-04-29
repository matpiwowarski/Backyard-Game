#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
	double movementSpeed;
public:
	Player();
	~Player();


	//methods
	void move(const double &dt, const double xDirection, const double yDirection);
	void update(const double& dt);

};

