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
    cout << run.playfield;
    for(int i = 0; i < 100; i++)
    {
        cout << "in for loop" << endl;
        run.updateMove();
        // run.moveRight();
        cout << run.playfield;
        /*
            TODO:
            - Add function that creates new block when the current block hits the floor / other blocks
            - Write moveRight function
            - Write slam function ( Just a for loop with moving down and checking for collision ever time. Simple stuff )
        */

    }
    return 0;
}
