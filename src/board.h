#pragma once
#include <iostream>
#include <vector>
using namespace std;

class board
{
    public:
        // Public variables
        int playField[20][10];

        // Public methods
        string printBoard();
        void resetBoard();
        void checkIfRow();
        void gravity();

        // Default contsructor
        board();

        // Overloaded constructors
        friend ostream& operator << (ostream &out, board &b);
    private:
        // Patterns for the blocks


        // Vector to store rows to apply gravity to
        vector<int> rows;
};
