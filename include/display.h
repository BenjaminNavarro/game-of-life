#pragma once

namespace conway {

class GameOfLife;

class Display {
public:
	Display(const GameOfLife& game);

	void render(char empty_cell = ' ', char populated_cell = '*') const;

private:
	const GameOfLife& game_;
};

}
