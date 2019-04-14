#include "Game.h"

// initialization

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "BACKYARD GAME");
}

// constructors/destructors

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

// funtions

void Game::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateSFMLEvents();
}

void Game::render()
{
	this->window->clear();
	// render items

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}
