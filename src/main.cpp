#include <conway.h>

#include <fmt/format.h>

#include <chrono>
#include <thread>

int main() {
	auto game = conway::GameOfLife{40, 20};
	auto display = conway::Display{game};

	// Glider
	// game.setCellState(5, 2, conway::State::Populated);
	// game.setCellState(6, 2, conway::State::Populated);
	// game.setCellState(7, 2, conway::State::Populated);
	// game.setCellState(7, 1, conway::State::Populated);
	// game.setCellState(6, 0, conway::State::Populated);

	// Exploder
	game.setCellState(20, 10, conway::State::Populated);
	game.setCellState(21, 10, conway::State::Populated);
	game.setCellState(22, 10, conway::State::Populated);
	game.setCellState(21, 9, conway::State::Populated);
	game.setCellState(20, 11, conway::State::Populated);
	game.setCellState(22, 11, conway::State::Populated);
	game.setCellState(21, 12, conway::State::Populated);


	for (size_t i = 0; i < 20; ++i) {
		fmt::print("\x1B[2J\x1B[H"); // Clear the console, UNIX only
		fmt::print("=======   Generation #{}   =======\n", i+1);

		display.render();

		game.run();

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}
