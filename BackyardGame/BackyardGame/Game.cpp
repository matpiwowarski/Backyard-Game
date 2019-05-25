#include "Game.h"

// initialization

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "BACKYARD GAME");
}

void Game::initStates()
{
	this->states.push(new BackyardState(this->window));
}

// constructors/destructors

Game::Game()
{
	this->initWindow();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

// methods

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

	if (!this->states.empty())
	{
		if (this->states.top()->hasEnteredHouse())
		{
			this->states.push(new HouseState(this->window)); 
		}
		else if (this->states.top()->hasEnteredGarden())
		{
			this->states.push(new GardenState(this->window)); 
		}
		else if (this->states.top()->hasBackToBackyard())
		{
			this->states.pop(); // DELETE HOUSESTATE/GARDENSTATE
			this->states.top()->setBackToBackyard(false);
			this->states.top()->setEnetredHouse(false);
			this->states.top()->setEnteredGarden(false);
		}

		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) // if getQuit() == true
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else // end program
	{
		this->endGame();
	}

}

void Game::render()
{
	this->window->clear();
	
	// render items
	if (!this->states.empty())
		this->states.top()->render(this->window);

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

void Game::endGame()
{
	std::cout << "GAME OVER" << std::endl;
	this->window->close();
}
