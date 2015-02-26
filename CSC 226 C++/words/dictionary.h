#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>
#include <vector>
#include <string>
// Course: CSC 236 Data Structures
// Name: Eddie Greathouse
// Final Project: <Words, a game where you create as many words as possible>
/*
    Purpose: <This file lists all the functions and variable necessary to load the dictionary used in the game.
                This file works by inputting a text file, and saving each word as an element in a vector. This class can
                also compare a string to a string in the vector.>
*/
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;
class dictionary
{
    public:
        dictionary();
        virtual ~dictionary();
        ifstream in_stream;
        vector<string> all_words;
        string temp;
        void display();
        bool verify(string a_word);
        void load_file();
    protected:
    private:
};

#endif // DICTIONARY_H
