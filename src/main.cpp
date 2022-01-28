/*
TetrisMaster
https://github.com/Mindcool25/tetrismaster
Written by Zach Marshall, AI implementation and debugging by Kyle Tracy
made using https://tetris.fandom.com/wiki/Tetris_Guideline as a guideline for game rules and such
*/
#include <iostream>
#include <Python.h>
#include "Headers/board.hpp"
#include "Headers/game.hpp"

// This stuff is for cross platform delay
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

using namespace std;




int main()
{
    int test;
    int RandMove;
    cout << "TetrisMaster\nC++ Edition\n" << endl;
    game run;
    cout << run.playfield;
    while(run.running)
    {
        system("clear");
        RandMove = (rand()%4);
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
        case 3:
            run.rotateLeft();
            break;
        case 4:
            run.rotateRight();
            break;
        }
        cout << run.playfield;
        run.updateMove();
        //std::system("clear");
        cout << run.playfield;
        /*
            TODO:
            D Add function that creates new block when the current block hits the floor / other blocks
            D Write moveRight function
            D Write slam function ( Just a for loop with moving down and checking for collision ever time. Simple stuff )
<<<<<<< Updated upstream
            - Write end game condition
            - Add framing and delay
            - Clear screen
=======
            D Write end game condition
            D Add framing and delay
            D Clear screen
>>>>>>> Stashed changes
            D Add rotate block methods
            D Force change for github
        */

    }
    cout << run.score << endl;
    return 0;
}
