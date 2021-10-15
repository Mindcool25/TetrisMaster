#include <iostream>
#include "block.h"

using namespace std;

// Setting initial blockshape, default is type 1
Block::Block()
{
    blocktype = 0;
	rotation = 0;
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