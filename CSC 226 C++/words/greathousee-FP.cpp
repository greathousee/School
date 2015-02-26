// Course: CSC 236 Data Structures
// Name: Eddie Greathouse
// Final Project: <Words, a game where you create as many words as possible>
/*
    Purpose: <This file contains main(). In other words, this is the driver file that starts and ends the game. It
                is merely 3 lines of code.>
*/
#include <iostream>
#include <fstream>
#include <string>
//The following three libraries come from: http://www.cplusplus.com/reference/ctime/clock/
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */
#include "features.h"

using namespace std;

int main()
{
    features game;
    game.end_game();
    return 0;
}
