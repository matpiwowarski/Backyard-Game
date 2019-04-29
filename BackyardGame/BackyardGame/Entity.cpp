#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(32.f, 32.f));
}

Entity::~Entity()
{
}

void Entity::setPositionAndSize(float xPosition, float yPosition, float xSize, float ySize)
{
	this->shape.setSize(sf::Vector2f(xSize, ySize));
	this->shape.setPosition(sf::Vector2f(xPosition, yPosition));
}

void Entity::setTexture(const sf::Texture texture)
{
	sprite.setTexture(texture);
}

sf::RectangleShape Entity::getShape() const
{
	return shape;
}

void Entity::update(const double & dt)
{

}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
	target->draw(this->sprite);
}
