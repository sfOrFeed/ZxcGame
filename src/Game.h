
#ifndef ZXCGAME_SRC_GAME_H_
#define ZXCGAME_SRC_GAME_H_

#include <SFML/Graphics.hpp>

namespace zxc
{

	class Game
	{
	 public:
		Game(const Game& game) = delete;
		auto operator=(const Game& game) -> Game& = delete;

		explicit Game(const unsigned& wight = 1100, const unsigned& height = 800);
	 public:
		auto run(const unsigned& min_fps = 60) -> void;
	 private:
		auto processEvents() -> void;
		auto update(sf::Time delta) -> void;
		auto render() -> void;

		sf::RenderWindow _window;

	};

}

#endif //ZXCGAME_SRC_GAME_H_
