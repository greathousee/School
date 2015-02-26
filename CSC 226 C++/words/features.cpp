// Course: CSC 236 Data Structures
// Name: Eddie Greathouse
// Final Project: <Words, a game where you create as many words as possible>
/*
    Purpose: <This file contains all the function definitions used in creating the game.>
*/
#include "features.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "dictionary.h"
#include <cstdlib>
#include <ctime>
using namespace std;
features::features()
{
    //testing the comparison of string entered by user and the vector that contains the dictionary file
    //a smaller file has been created to better testing called testing.txt
    string test1;
    cout << "enter string" << endl;
    cin >> test1;
    dict_file.verify(test1);
    //finishes the creation of the 2D that will store random char
    for (int i=0; i<2; i++)
    {
        random_array[i] = new char[1];
    }
    generate_letters();
}
features::~features()
{
    //dtor
}
void features::generate_letters()
{
    srand(time(0));  // Initialize random number generator.
    rand(); //throw away first call
    int num = rand() % 26;  // Number in the range [ 0...25 ]
    char upper = static_cast<char>( 'A' + num ); // Convert to upper case
    for (int p=0; p<=2; p++)
        for (int q=0; q<=2; q++)
    {
        random_array[q][p] = upper;
    }
}
int features::timer()
{
    //The following is provided by: http://www.daniweb.com/software-development/cpp/code/216933/a-countdown-timer-in-c
    //& the help of Dr. Jan Pearce
   clock_t t, s, passed, left;
    time(&t);
    system("pause");
    time(&s);
    passed = difftime(s, t);
    time(&s);
    passed = difftime(s, t);
    left = 30-passed;
    return left;
}
void display_board() //After giving up on the string issue, I wrote the rest of the program as best as I could
{ //The error in the function is strange. I used the same syntax in assignment 5 for accessing an element in a 2D array.
//random_array is declared in the header file for features.
    cout << "| " << random_array[0][0] << " | " << random_array[1][0] << " | " << random_array[2][0] << "/t" << timer() << endl;
    cout << "| " << random_array[0][1] << " | " << random_array[1][1] << " | " << random_array[2][1] << "/t" << "Words: " << score << endl;
    cout << "| " << random_array[0][2] << " | " << random_array[1][2] << " | " << random_array[2][2] << endl << endl;
    cout << "Type a word and press enter:" << endl;
}
void add_score()
{
    score = score+1;
}
void end_game()
{
    char again='y';
    system("CLS");
    cout << "Game over" << endl << endl;
    cout << "Your final score is:" << endl;
    cout << score;
    cout << "Would you like to play again? ('y' or 'Y' for yes)" << endl;
    cin >> again;
    while (again == 'y' || again == 'Y')
    {
        features game;
    }
    return 0;
}
