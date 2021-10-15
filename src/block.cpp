#include <iostream>
#include "block.h"

using namespace std;

// Setting initial blockshape, default is type 1
Block::Block()
{
    blocktype = 0;
	rotation = 0;
}

Block::Block(int shape, int blockrotation)
{
	blocktype = shape;
	rotation = blockrotation;
}

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