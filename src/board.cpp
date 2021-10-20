#include <iostream>
#include "board.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "colors.h"

using namespace std;

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
            playField[i][j] = rand() % 8;
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
			for (int i = 0; i < rows.size(); i++)
			{
			}
        }

    }
}

void board::gravity()
{
	// Iterate through vector
	for (int i = 0; i < rows.size(); i++)
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
        out << fg_white << "|";
        for (int j = 0; j < 10; j++)
        {
            switch(t.playField[i][j])
            {
				case 0:
					out << fg_white << " . ";
					break;
                case 1:
                    out << fg_cyan << t.iPattern;
					break;
                case 2:
                	out << fg_yellow << t.oPattern;
					break;
            	case 3:
					out << fg_purple << t.tPattern;
					break;
				case 4:
					out << fg_green << t.sPattern;
					break;
				case 5:
					out << fg_red << t.zPattern;
					break;
				case 6:
					out << fg_blue << t.jPattern;
					break;
				case 7:
					out << fg_orange << t.lPattern;
					break;
            }
        }
        out << fg_white << "|\n";
    }
	out << fg_white << "________________________________\n";
    return out;
};