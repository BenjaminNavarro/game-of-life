
#include <conway.h>

namespace conway {

GameOfLife::GameOfLife(size_t width, size_t height) {
	resize(width, height);
}

void GameOfLife::resize(size_t width, size_t height) {
	grid_.resize(width*height, State::Empty);
	width_ = width;
	height_ = height;
}

size_t GameOfLife::getWidth() const {
	return width_;
}

size_t GameOfLife::getHeight() const {
	return height_;
}

State GameOfLife::getCellState(size_t x, size_t y) const {
	if(x >= width_) {
		return State::Empty;
	}
	else if(y >= height_) {
		return State::Empty;
	}
	else {
		return grid_[x + y*width_];
	}

}

void GameOfLife::setCellState(size_t x, size_t y, State new_state) {
	if(x < width_ and y < height_) {
		grid_[x + y*width_] = new_state;
	}
}

size_t GameOfLife::countNeighbours(size_t x, size_t y) const {
	size_t neighbours = 0;

	for (size_t i = x-1; i <= x+1; ++i) {
		for (size_t j = y-1; j <= y+1; ++j) {
			if(i == x and j == y) {
				continue;
			}
			if(getCellState(i,j) == State::Populated) {
				++neighbours;
			}
		}
	}

	return neighbours;
}

void GameOfLife::run(size_t generations) {
	GameOfLife new_state = *this;

	for (size_t generation = 0; generation < generations; ++generation) {
		for (size_t j = 0; j < height_; ++j) {
			for (size_t i = 0; i < width_; ++i) {
				auto neighbours = countNeighbours(i, j);
				if(getCellState(i, j) == State::Populated) {
					if(neighbours <= 1 or neighbours >= 4) {
						// Not enough/too many neighbours, the cell dies
						new_state.setCellState(i, j, State::Empty);
					}
				}
				else {
					if(neighbours == 3) {
						// a new cell is created
						new_state.setCellState(i, j, State::Populated);
					}
				}
			}
		}
	}

	*this = new_state;
}

}
