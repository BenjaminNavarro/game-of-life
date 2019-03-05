#include <display.h>
#include <game_of_life.h>

#include <fmt/format.h>

namespace conway {

Display::Display(const GameOfLife& game) :
	game_(game)
{

}

void Display::render(char empty_cell, char populated_cell) const {

	for (size_t j = 0; j < game_.getHeight(); ++j) {
		for (size_t i = 0; i < game_.getWidth(); ++i) {
			if(game_.getCellState(i, j) == State::Empty) {
				fmt::print("{}", empty_cell);
			}
			else {
				fmt::print("{}", populated_cell);
			}
		}
		fmt::print("\n");
	}

}

}
