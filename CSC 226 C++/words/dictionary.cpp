// Course: CSC 236 Data Structures
// Name: Eddie Greathouse
// Final Project: <Words, a game where you create as many words as possible>
/*
    Purpose: <This file contains the function definitions for loading the dictionary.>
*/
#include "dictionary.h"
#include<iostream>
#include<fstream>
//Some of these libraries are not necessary and would've been removed when the project finished
#include<sstream>
#include<string>
#include<cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <algorithm>
#include <cctype>

dictionary::dictionary()
{
    load_file();
    cout << "Loaded dictionary successfully" << endl; //will remove after debugging
}

dictionary::~dictionary()
{
    //dtor
}

void dictionary::display()
{
    for(int t=0;t<all_words.size();t++)
    {
        cout<<all_words.at(t)<< endl;
    }
}
bool dictionary::verify(string a_word)
{
    //This section of the code has been difficult to solve
    string query; //This string will represent a string entered by the user after debugging
    cout << "verify\n" << endl;
    for (int it=0; it<all_words.size()-1; it++)
    {
        query = all_words.at(it);
        cout << query << endl;
        if (query.compare(a_word) == 0)
        {
            cout << "Found: " << endl;
        }
    }
    /*if (std::find(all_words.begin(), all_words.end(), a_word) != all_words.end())
        {
        cout << "success!" << endl;
        }*/
}
void dictionary::load_file() // Big O analysis
{
    in_stream.open("dictionary.txt");
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    all_words.clear();
    while(!(in_stream.eof()))
    {
        in_stream >> temp;
        temp+=" ";
        all_words.push_back(temp);
    }
}
