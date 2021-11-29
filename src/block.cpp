#include <iostream>
#include "block.h"

using namespace std;

// Setting initial blockshape, default is type 1
Block::Block()
{
    blocktype = 0;
	rotation = 0;

	/*
	X and Y stuff is weird. 0 0 will put the block in the top left hand corner,
	and when referring to x and y for array stuff make sure to put [y][x]
	just fun array stuff there.
	*/
	x = 3;
	y = -1;

	// Setting hit bottom to false
	bool hitbottom = false;
}

// Allowing for non default values
Block::Block(int shape, int blockrotation)
{
	blocktype = shape;
	rotation = blockrotation;
}

// Rotating 90 degrees counterclockwise
void Block::rotateLeft()
{
	if(rotation == 0)
	{
		rotation = 3;
	}
	else
	{
		rotation --;
	}
}

// Rotating 90 degrees clockwise
void Block::rotateRight()
{
	if (rotation == 3)
	{
		rotation = 0;
	}
	else
	{
		rotation ++;
	}
}

// moving left
void Block::moveLeft()
{
	x--;
}

// moving right
void Block::moveRight()
{
	x++;
}

void Block::moveDown()
{
    y++;
}

void Block::reset()
{
    blocktype = 0;
	rotation = 0;

	/*
	X and Y stuff is weird. 0 0 will put the block in the top left hand corner,
	and when referring to x and y for array stuff make sure to put [y][x]
	just fun array stuff there.
	*/
	x = 3;
	y = -1;

	// Setting hit bottom to false
	bool hitbottom = false;
}
