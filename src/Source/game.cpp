#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include <iostream>
#include "../Headers/game.hpp"
#include "../Headers/block.hpp"
#include "../Headers/board.hpp"

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

    // Placing first block
    writeToBoard();
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
    // DEBUG cout << "Checking..." << endl;
    // DEBUG cout << "Rotation: " << rotateval << endl;
    // DEBUG cout << "Movex: " << movex << endl;
    // DEBUG cout << "Movey: " << movey << endl;
    bool moveable = true;
    int clearboard[20][10];//y, x
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
                //   need to add the block x and y to clear correct array elements
                clearboard[b.y + i][b.x + j] = 0;
                // DEBUG cout << "!";
            }
            else
            {
                // DEBUG cout << "_";
            }
            // DEBUG cout << "c" <<clearboard[b.y + i][b.x + j] << "(" <<b.blockshape[b.blocktype][b.rotation][i][j]<<")";
        }
        cout << endl;
    }

    // check for collisions with intended transformation, only check the spots that != 0
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            // Making sure that the space it is searching is indeed not 0
            if(b.blockshape[b.blocktype][b.rotation + rotateval][i][j] != 0)
            {
                if(clearboard[b.y + i + movey][b.x + j + movex] != 0)
                {
                    // If there is a collision, change moveable to false
                    cout << clearboard[b.y + i + movey][b.x + j + movex] << endl;
                    moveable = false;
                    break;
                }
                if(b.y + i + movey > 19 || b.x + j + movex > 9 || b.x + j + movex < 0 || b.y + i + movey > 20)
                {
                    moveable = false;
                    break;
                }
            }
        }
    }
    return moveable;
}

// Writing current block in regards to its coordinates to the board
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

// Method to clear the board before writing to it
void game::clearBoard()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if (b.blockshape[b.blocktype][b.rotation][i][j] != 0)
            {
                // replace every nonzero block spot to zero
                playfield.playField[b.y + i][b.x + j] = 0;
            }
        }
    }
}

// Updating the game board
void game::updateMove()
{
    if (canMove(0, 0, 1))
    {
        clearBoard();
        b.moveDown();
    }
    else
    {
        if(!b.hitbottom)
        {
            b.hitbottom = true;
            // DEBUG cout << "hit bottom" << endl;
        }
        else
        {
            int lines = playfield.gravity();
            if (lines == 1)
            {
                score += onelineBonus;
            }
            else if (lines == 2)
            {
                score += twolineBonus;
            }
            else if (lines == 3)
            {
                score += threelineBonus;
            }
            else if (lines == 4)
            {
                score += tetrisBonus;
            }
            score += placeBonus;

            // DEBUG cout << "Creating new block?" << endl;

            b.reset();

            if(!canSpawn())
            {
                cout << "GAME OVER" << endl;
                running = false;
            }
        }

    }
    writeToBoard();
}

// Checking if the block can move left, if so move block left
void game::moveLeft()
{
    // Clearing the board to check for collisions
    clearBoard();
    if(canMove(0, -1, 0))
    {
        // Moving left if possible
        b.moveLeft();
    }
    // Writing to board regardless if it moved or not
    writeToBoard();
}

// Checking if block can move right, if so move right
void game::moveRight()
{
    // Clearing the board to check for collisions
    clearBoard();
    if(canMove(0, 1, 0))
    {
        // Moving left if possible
        b.moveRight();
    }
    // Writing to board regardless if it moved or not
    writeToBoard();
}

void game::rotateLeft()
{
    // Clearing the board to check for collisions
    clearBoard();
    if(canMove(-1, 0, 0))
    {
        // Moving left if possible
        b.rotateLeft();
    }
    // Writing to board regardless if it moved or not
    writeToBoard();
}

void game::rotateRight()
{
    clearBoard();
    if(canMove(1, 0, 0))
    {
        b.rotateRight();
    }
    writeToBoard();
}

bool game::canSpawn()
{
    bool moveable = true;
    // check for collisions with intended transformation, only check the spots that != 0
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            // Making sure that the space it is searching is indeed not 0
            if(b.blockshape[b.blocktype][b.rotation][i][j] != 0)
            {
                if(playfield.playField[b.y + i][b.x + j] != 0)
                {
                    // If there is a collision, change moveable to false
                    // DEBUG cout << clearboard[b.y + i + movey][b.x + j + movex] << endl;
                    moveable = false;
                    cout << "Hit another thing" << endl;
                    break;
                }

            }
        }
    }
    return moveable;
}
