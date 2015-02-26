// Course: CSC 236 Data Structures
// Name: Eddie Greathouse
// Final Project: <Words, a game where you create as many words as possible>
/*
    Purpose: <This file contains all the functions and variables used for the game.
                This file is responsible for all features of the game such as displaying the board,
                keeping the score, managing the timer, and generating random letters.>
*/
#ifndef FEATURES_H
#define FEATURES_H
#include <iostream>
#include <fstream>
#include <string>
//Libraries provided by: http://www.cplusplus.com/reference/ctime/clock/
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */
#include "dictionary.h"
using namespace std;

struct link
{
    char letter;
    link* nextlink;
};
class features
{
    public:
        features();
        virtual ~features();
        void generate_letters();
        int timer();
        int score;
        dictionary dict_file;
        void display_board();
        void add_score();
        void end_game();
        char **random_array = new char*[2]; //a pointer pointing to a 2D array of characters
    protected:
    private:

};

#endif // FEATURES_H
