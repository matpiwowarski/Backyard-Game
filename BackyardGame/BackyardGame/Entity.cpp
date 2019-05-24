#include "Entity.h"

Entity::Entity()
{
	this->sprite.setScale(sf::Vector2f(2.f, 2.f));
}

Entity::~Entity()
{
}

void Entity::setSpritePosition(double xPosition, double yPosition)
{
	this->sprite.setPosition(sf::Vector2f(xPosition, yPosition));
}

void Entity::setTexture(const sf::Texture texture)
{
	sprite.setTexture(texture);
}

sf::Sprite & Entity::getSprite()
{
	return sprite;
}

sf::Vector2f Entity::getPosition() const
{
	return sprite.getPosition();
}

void Entity::update(const double & dt)
{

}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}
