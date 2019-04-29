#include "Entity.h"

Entity::Entity()
{
	this->sprite.setScale(sf::Vector2f(2.f, 2.f));
}

Entity::~Entity()
{
}

void Entity::setPositionAndSize(float xPosition, float yPosition, float xSize, float ySize)
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

void Entity::update(const double & dt)
{

}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}
