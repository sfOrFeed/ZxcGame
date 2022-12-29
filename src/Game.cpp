
#include "Game.h"
zxc::Game::Game(const unsigned int& wight, const unsigned int& height)
	: _window(sf::VideoMode(wight, height), "Game")
{

}

auto zxc::Game::run(const unsigned int& min_fps) -> void
{
	sf::Clock clock;
	sf::Time last_step;
	sf::Time fixed_step = sf::seconds(1.f / static_cast<float>(min_fps));

	while (_window.isOpen())
	{
		processEvents();
		last_step = clock.restart();
		while (last_step > fixed_step)
		{
			last_step -= fixed_step;
			update(fixed_step);
		}
		update(last_step);
		render();
	}
}

auto zxc::Game::processEvents() -> void
{
	sf::Event event{};

	while (_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			_window.close();
		default:
			break;
		}
	}

}

auto zxc::Game::update(sf::Time delta) -> void
{

}

auto zxc::Game::render() -> void
{
	_window.clear();
	_window.display();
}
