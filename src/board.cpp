#include <iostream>
#include "board.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "colorswin.h"

using namespace std;

board::board()
{
    resetBoard();
}

// Resetting board to all 0s
void board::resetBoard()
{
    srand(time(NULL));
    // Loop through entire array
    for (int i = 0; i < 20; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            // Set current spot to 0
            playField[i][j] = 0;//rand() % 8; // FOR TESTING
        }
    }
}

void board::checkIfRow()
{
    bool fullrow;
	rows.clear();
    for (int i = 0; i < 20; i ++)
    {
        fullrow = true;
        for (int j = 0; j < 10; j ++)
        {
            if (playField[i][j] == 0)
            {
                fullrow = false;
            }
        }
        if (fullrow == true)
        {
			rows.push_back(i);
        }

    }
}

void board::gravity()
{
	// Iterate through vector
	for (int i = 0; i < (int)rows.size(); i++)
	{
		for(int j = rows[i]; j > 0; j --)
		{
			for (int k = 0; k < 10; k ++)
			{
				playField[j][k] = playField[j-1][k];
			}
		}
		for (int k = 0; k < 10; k ++)
		{
				playField[0][k] = 0;
		}
 	}
}

ostream& operator << (ostream &out, board &t)
{
    // Loop through entire array
    for (int i = 0; i < 20; i++)
    {
        out << "|";
        for (int j = 0; j < 10; j++)
        {
            switch(t.playField[i][j])
            {
				case 0:
					out << " . ";
					break;
                case 1:
                    out << iPattern;
					break;
                case 2:
                	out << oPattern;
					break;
            	case 3:
					out << tPattern;
					break;
				case 4:
					out << sPattern;
					break;
				case 5:
					out << zPattern;
					break;
				case 6:
					out << jPattern;
					break;
				case 7:
					out << lPattern;
					break;
            }
        }
        out << "|\n";
    }
	out << "________________________________\n";
    return out;
};
