#pragma once
#include "../Headers/block.hpp"
#include "../Headers/board.hpp"

class game{
	public:
		// Constructors
		game();
		game(board playfield, Block b, int = 5, int = 15, int = 30, int = 40, int = 50);

		// variables
		// score bonus values
		int placeBonus, onelineBonus, twolineBonus, threelineBonus, tetrisBonus;

		// score value, starts at 0
		int score = 0;

		// Objects that imma use later
		board playfield;
		Block b;

		// Public movement methods
		void moveLeft();
		void moveRight();
		void rotateLeft();
		void rotateRight();

		// Main game play loop items
		// Writing block to board
		void writeToBoard();
		void clearBoard();
		// Updating the
		void updateMove();

	private:
		// private methods
		// checking if the intended movement is possible
		bool canMove(int rotateval = 0, int movex = 0, int movey = 0);
		// Moving down once
		void moveDown();
};
