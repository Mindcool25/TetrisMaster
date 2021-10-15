/*
TetrisMaster
Written by Zach Marshall
made using https://tetris.fandom.com/wiki/Tetris_Guideline as a guideline for game rules and such
*/
#include <iostream>
#include "board.h"

using namespace std;




int main()
{
    cout << "TetrisMaster\nC++ Edition\n" << endl;
    board play;
    play.resetBoard();
    cout << play;
    play.checkIfRow();
    play.gravity();
    cout << play;
}
