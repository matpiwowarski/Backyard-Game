#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(32.f, 32.f));
	this->movementSpeed = 100.f;
}


Entity::~Entity()
{
}

void Entity::move(const double &dt, const double xDirection, const double yDirection)
{
	this->shape.move(xDirection * this->movementSpeed * dt, yDirection * this->movementSpeed * dt);
}

void Entity::update(const double & dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if(this->shape.getPosition().x > 0 )
			this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (this->shape.getPosition().x < 768)
			this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (this->shape.getPosition().y > 0)
			this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (this->shape.getPosition().y < 545)
			this->move(dt, 0.f, 1.f);
}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
