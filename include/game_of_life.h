#pragma once

#include "common.h"
#include <vector>

namespace conway {

class GameOfLife {
public:
	GameOfLife() = default;
	GameOfLife(size_t width, size_t height);

	void resize(size_t width, size_t height);
	size_t getWidth() const;
	size_t getHeight() const;

	State getCellState(size_t x, size_t y) const;
	void setCellState(size_t x, size_t y, State new_state);

	size_t countNeighbours(size_t x, size_t y) const;

	void run(size_t generations = 1);

private:
	size_t width_;
	size_t height_;
	std::vector<State> grid_; // storage is row major
};

}
