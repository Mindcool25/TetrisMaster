/*
TetrisMaster
Written by Zach Marshall
made using https://tetris.fandom.com/wiki/Tetris_Guideline as a guideline for game rules and such
*/
#include <iostream>
#include "board.h"
#include "game.h"

using namespace std;




int main()
{
    cout << "TetrisMaster\nC++ Edition\n" << endl;
    game run;
    cout << "Empty board" << endl;
    cout << run.playfield;
    cout << "Board with a block (Hopefully)" << endl;
    run.writeToBoard();
    cout << run.playfield;

    return 0;
}
