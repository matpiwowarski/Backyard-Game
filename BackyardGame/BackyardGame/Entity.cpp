#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(16.f, 16.f));
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
		this->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->move(dt, 0.f, 1.f);
}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
