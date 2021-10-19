#pragma once
#include "block.h"
#include "board.h"

class game{
	public:	
		// Contructors
		game();
		game(board, Block, int, int, int, int, int);

		// variables
		// score bonus values
		int placeBonus, onelineBonus, twolineBonus, threelineBonus, tetrisBonus;

		// score value, starts at 0
		int score = 0;
	
	private:
		// private methods
		// checking if the intended movement is possible
		bool canMove(int[3]);
		// Writing the block to the board, and write to board class
		void writeToBoard();
		// Moving down once, 
		void moveDown();
};