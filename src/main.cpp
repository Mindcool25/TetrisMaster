/*
TetrisMaster
Written by Zach Marshall
made using https://tetris.fandom.com/wiki/Tetris_Guideline as a guideline for game rules and such
*/
#include <iostream>
#include "Headers/board.hpp"
#include "Headers/game.hpp"


using namespace std;




int main()
{
    int RandMove;
    cout << "TetrisMaster\nC++ Edition\n" << endl;
    game run;
    cout << run.playfield;
    for(int i = 0; i < 300; i++)
    {
        system("clear");
        RandMove = (rand()%2);
        switch (RandMove)
        {
        case 0:
            run.moveRight();
            break;
        case 1:
            run.moveLeft();
            break;
        case 2:
            run.moveRight();
            break;
        }
        //cout << run.playfield;
        run.updateMove();
        cout << run.playfield;
        /*
            TODO:
            D Add function that creates new block when the current block hits the floor / other blocks
            D Write moveRight function
            - Write slam function ( Just a for loop with moving down and checking for collision ever time. Simple stuff )
            - Write end game condition
            - Add framing and delay
            - Clear screen
        */

    }
    return 0;
}
