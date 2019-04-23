#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <stack>

class Entity
{
protected:
	sf::RectangleShape shape;
	double movementSpeed;
public:
	Entity();
	virtual ~Entity();

	// methods
	virtual void move(const double &dt, const double xDirection, const double yDirection);
	virtual void update(const double& dt); // = 0
	virtual void render(sf::RenderTarget * target); // = 0
};

