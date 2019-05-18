#include "Player.h"



Player::Player()
{
	this->movementSpeed = 300.f;
}


Player::~Player()
{
}

bool Player::getIsBlocked() const
{
	return isBlocked;
}

void Player::move(const double &dt, const double xDirection, const double yDirection)
{
	if(!this->isBlocked)
		this->sprite.move(xDirection * this->movementSpeed * dt, yDirection * this->movementSpeed * dt);
}

void Player::update(const double & dt)
{
	if (!isBlocked)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			if (this->sprite.getPosition().x > 0)
				this->move(dt, -1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			if (this->sprite.getPosition().x < 768)
				this->move(dt, 1.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			if (this->sprite.getPosition().y > 0)
				this->move(dt, 0.f, -1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			if (this->sprite.getPosition().y < 545)
				this->move(dt, 0.f, 1.f);
	}
}

void Player::block()
{
	isBlocked = true;
}

void Player::unblock()
{
	isBlocked = false;
}


