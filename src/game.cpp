// This stuff is for crossplatform delay
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include <iostream>
#include "game.h"
#include "block.h"
#include "board.h"

using namespace std;

// Default constructor
game::game()
{
    // Setting up initial objects
    board playfield;
    Block b;

    // Setting initial point values
    placeBonus = 5;
    onelineBonus = 15;
    twolineBonus = 30;
    threelineBonus = 40;
    tetrisBonus = 50;
}

// Overloaded constructor
game::game(board bo, Block bl, int place, int one, int two, int three, int tetris)
{
    // Setting objects
    board playfield = bo;
    Block b = bl;

    // Setting point values
    placeBonus = place;
    onelineBonus = one;
    twolineBonus = two;
    threelineBonus = three;
    tetrisBonus = tetris;
}

// Private methods
bool game::canMove(int rotateval, int movex, int movey)
{
    bool moveable = true;
    int clearboard[20][10];
    // create a copy of the board array so we have a non-destructive way of checking collisions
    // Has to be done through a loop... one thing python does better right there
    // Oh well, c++ faster and speed is what I need
    for(int i = 0; i < 20; i++)
    {
	    for(int j = 0; j < 10; j++)
	    {
		    clearboard[i][j] = playfield.playField[i][j];
	    }
    }
    // clear the old block from the board to not detect itself
    // Done through a loop again (thanks c++)
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if (b.blockshape[b.blocktype][b.rotation][i][j] != 0)
            {
                // replace every nonzero block spot to zero
                clearboard[i][j] = 0;
            }
        }
    }
    // check for collisions with intended transformation, only check the spots that != 0
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            // Making sure that the space it is searching is indeed not 0
            if(b.blockshape[b.blocktype][b.rotation][i][j] != 0)
            {
                if(clearboard[b.y + i][b.x + j] != 0)
                {
                    moveable = false;
                }
            }
        }
    }
    // If there is a collision, change moveable to false

    return moveable;
}

void game::writeToBoard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if (b.blockshape[b.blocktype][b.rotation][i][j] != 0)
            {
                // replace every nonzero block spot to what it should be
                playfield.playField[b.y + i][b.x + j] = b.blockshape[b.blocktype][b.rotation][i][j];
            }
        }
    }
}

void game::updateMove()
{

}
