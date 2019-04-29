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
	sf::Sprite sprite;
public:
	Entity();
	virtual ~Entity();

	// getters/setters
	void setPositionAndSize(float xPosition, float yPosition, float xSize, float ySize);
	void setTexture(const sf::Texture texture);
	sf::Sprite & getSprite();

	// methods
	virtual void update(const double& dt);
	virtual void render(sf::RenderTarget * target);// = 0;
};

