#pragma once
#include "block.h"
#include "board.h"

class game{
	public:	
		// Contructors
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
		void writeToBoard();
	
	private:
		// private methods
		// checking if the intended movement is possible
		bool canMove(int = 0, int = 0, int = 0);
		// Writing the block to the board, and write to board class
		
		// Moving down once, 
		void moveDown();
};
