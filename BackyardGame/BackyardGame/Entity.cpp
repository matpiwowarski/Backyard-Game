#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(32.f, 32.f));

}


Entity::~Entity()
{
}



void Entity::update(const double & dt)
{

}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
